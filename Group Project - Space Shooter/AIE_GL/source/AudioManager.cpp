#include "AudioManager.h"
#include "sndfile.hh"
#include "Audio.h"

AudioManager* AudioManager::m_pInstance = nullptr;

// ----------------------------------------------------------------------------------------
// Get the size of one audio sample based on the file format.
//----------------------------------------------------------------------------------------
static int GetSampleSize(int format)
{
	int subFormat = format & SF_FORMAT_SUBMASK;
	switch (subFormat)
	{
	case SF_FORMAT_PCM_16:		return sizeof(short);
	case SF_FORMAT_GSM610:		return sizeof(short);
	case SF_FORMAT_DWVW_16:		return sizeof(short);
	case SF_FORMAT_DPCM_16:		return sizeof(short);
	case SF_FORMAT_VORBIS:		return sizeof(short);
	case SF_FORMAT_ALAC_16:		return sizeof(short);
	case SF_FORMAT_PCM_U8:		return sizeof(unsigned char);

	//Untested formats
	case SF_FORMAT_PCM_24:		return sizeof(char[3]);
	case SF_FORMAT_DWVW_24:		return sizeof(char[3]);
	case SF_FORMAT_ALAC_24:		return sizeof(char[3]);
	case SF_FORMAT_PCM_32:		return sizeof(int);
	case SF_FORMAT_ALAC_32:		return sizeof(int);
	case SF_FORMAT_FLOAT:		return sizeof(float);
	case SF_FORMAT_DOUBLE:		return sizeof(double);
	
	default:					return sizeof(char);
	}
}

//----------------------------------------------------------------------------------------
// Convert the libsndfile format enum into a compatible OpenAL format enum.
//----------------------------------------------------------------------------------------
static int GetOpenALFormat(int fileFormat, int channels)
{
	int subFormat = fileFormat & SF_FORMAT_SUBMASK;
	switch(subFormat)
	{
		case SF_FORMAT_PCM_16:
		case SF_FORMAT_DPCM_16:
		case SF_FORMAT_ALAC_16:
		case SF_FORMAT_VORBIS:
		case SF_FORMAT_GSM610:
		{
			if(channels > 1)
				return AL_FORMAT_STEREO16;
			
			return AL_FORMAT_MONO16;
		}
		default:
		{
			if(channels > 1)
				return AL_FORMAT_STEREO8;
			
			return AL_FORMAT_MONO8;
		}
	}
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
AudioManager::AudioManager()
{
	//Create OpenAL device and setup context.
	m_pOpenALDevice = alcOpenDevice(nullptr);
	m_pOpenALContext = alcCreateContext(m_pOpenALDevice, nullptr);
	alcMakeContextCurrent(m_pOpenALContext);

	//Create sources and buffers
	alGenSources(MAX_SOUNDS, m_aAudioSources);

	if(alGetError() != AL_NO_ERROR)
	{
		//error
		printf("Could not initialise OpenAL\n");
	}

	m_AudioList = nullptr;
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
AudioManager::~AudioManager()
{
	//Close OpenAL device
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(m_pOpenALContext);
	alcCloseDevice(m_pOpenALDevice);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void AudioManager::Update()
{
	Audio* pCurrent = m_AudioList;
	while (pCurrent)
	{
		int nSourceID = pCurrent->m_nSourceID;
		if(nSourceID >= 0)
		{
			if(!GetIsPlayingInternal(nSourceID) && !GetIsPausedInternal(nSourceID))
			{
				if(pCurrent->m_bLooping)
				{
					PlaySoundInternal(pCurrent);
				}
				else
				{
					//Unbind sound from source so other sounds can use it.
					alSourcei(m_aAudioSources[nSourceID], AL_BUFFER, 0);
					pCurrent->m_nSourceID = -1;
				}
			}
		}

		pCurrent = pCurrent->m_pNext;
	}
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
Audio* AudioManager::CreateSound(const char* filename)
{
	SNDFILE *infile;
	SF_INFO audioInfo;
	ALuint bufferID;

	//Open sound file using libsndfile.
	memset(&audioInfo, 0, sizeof(SF_INFO));
	if (!(infile = sf_open(filename, SFM_READ, &audioInfo)))
	{
		printf("Not able to open input file %s.\n", filename);
		puts(sf_strerror(NULL));
		return nullptr;
	}

	//Allocate enough memory to store the sound data.
	int sampleSize = GetSampleSize(audioInfo.format);
	int sampleCount = (int)audioInfo.frames * audioInfo.channels;
	void* pAudioData = malloc(sampleSize * sampleCount);
	if(!pAudioData)
	{
		printf("Not able to allocate memory for input file %s.\n", filename);
		sf_close(infile);
		return nullptr;
	}

	//Read in the sound data from the file using libsndfile.
	//sf_read_short() is the recommended function to read data from any file format.
	//Using sf_read_raw() if the file is PCM 8 because sf_read_short() seems to crash on these formats.
	//This might be a bug in libsndfile or at least undocumented behavior.
	if (sampleSize == 1)
		sf_read_raw(infile, pAudioData, sampleCount);
	else
		sf_read_short(infile, (short*)pAudioData, sampleCount);

	//Create OpenAL buffer and load the sound data into it.
	int format = GetOpenALFormat(audioInfo.format, audioInfo.channels);
	alGenBuffers(1, &bufferID);
	alBufferData(bufferID, format, pAudioData, sampleSize * sampleCount, audioInfo.samplerate);

	//Free memory and close file.
	free(pAudioData);
	sf_close(infile);

	//Create Audio instance and add to linked list.
	Audio* pAudio = new Audio(this, bufferID);
	if(m_AudioList)
	{
		pAudio->m_pNext = m_AudioList->m_pNext;
		m_AudioList->m_pNext = pAudio;
	}
	else
		m_AudioList = pAudio;

	return pAudio;
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void AudioManager::DestroySound(Audio* pAudio)
{
	if(!pAudio)
		return;

	//Stop sound if it is playing.
	StopSoundInternal(pAudio);

	//Delete the sound data.
	alDeleteBuffers(1, &pAudio->m_nBufferID);

	//Remove from linked list.
	Audio* pCurrent = m_AudioList;
	Audio* pPrev = nullptr;
	while(pCurrent)
	{
		if(pCurrent == pAudio)
			break;

		pPrev = pCurrent;
		pCurrent = pCurrent->m_pNext;
	}

	if(pPrev)
		pPrev->m_pNext = pCurrent->m_pNext;
	else
		m_AudioList = pCurrent->m_pNext;

	//Delete audio instance.
	delete pAudio;
}

//----------------------------------------------------------------------------------------
// Play a new sound, returns an ID which can be used to stop/start this sound in the future.
//----------------------------------------------------------------------------------------
void AudioManager::PlaySoundInternal(Audio* pAudio)
{
	if (!pAudio)
		return;

	//Check if sound has already been bound to a source.
	if(pAudio->m_nSourceID >= 0)
	{
		//If it's not already playing, play it.
		if(!GetIsPlayingInternal(pAudio->m_nSourceID))
		{
			SetPitchInternal(pAudio);
			SetGainInternal(pAudio);
			alSourcePlay(m_aAudioSources[pAudio->m_nSourceID]);
		}
	}
	else
	{
		//Sound not already bout to a source so find the next available one.
		int nSourceID = GetAvailableSource();

		//Bind sound to source.
		alSourcei(m_aAudioSources[nSourceID], AL_BUFFER, pAudio->m_nBufferID);
		pAudio->m_nSourceID = nSourceID;

		SetPitchInternal(pAudio);
		SetGainInternal(pAudio);

		//Play sound.
		alSourcePlay(m_aAudioSources[nSourceID]);
	}
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void AudioManager::StopSoundInternal(Audio* pAudio)
{
	if(pAudio && pAudio->m_nSourceID >= 0)
	{
		//Stop the sound.
		alSourceStop(m_aAudioSources[pAudio->m_nSourceID]);

		//Unbind sound from source so other sounds can use it.
		alSourcei(m_aAudioSources[pAudio->m_nSourceID], AL_BUFFER, 0);
		pAudio->m_nSourceID = -1;
	}
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void AudioManager::PauseSoundInternal(Audio* pAudio)
{
	if(pAudio && pAudio->m_nSourceID >= 0 && GetIsPlayingInternal(pAudio->m_nSourceID))
	{
		alSourcePause(m_aAudioSources[pAudio->m_nSourceID]);
	}
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
bool AudioManager::GetIsPlayingInternal(int nSourceID)
{
	if(nSourceID >= 0)
	{
		ALint state;
		alGetSourcei(m_aAudioSources[nSourceID], AL_SOURCE_STATE, &state);
		return (state == AL_PLAYING);
	}
	return false;
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
bool AudioManager::GetIsPausedInternal(int nSourceID)
{
	if (nSourceID >= 0)
	{
		ALint state;
		alGetSourcei(m_aAudioSources[nSourceID], AL_SOURCE_STATE, &state);
		return (state == AL_PAUSED);
	}
	return false;
}

//----------------------------------------------------------------------------------------
// Find the next available sound source.
//----------------------------------------------------------------------------------------
int AudioManager::GetAvailableSource()
{
	for(int i = 0; i < MAX_SOUNDS; ++i)
	{
		if(!GetIsPlayingInternal(i) && !GetIsPausedInternal(i))
			return i;
	}

	return 0;
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void AudioManager::SetPitchInternal(Audio* pAudio)
{
	if(pAudio && pAudio->m_nSourceID >= 0)
	{
		alSourcef(m_aAudioSources[pAudio->m_nSourceID], AL_PITCH, pAudio->m_fPitch);
	}
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void AudioManager::SetGainInternal(Audio* pAudio)
{
	if(pAudio && pAudio->m_nSourceID >= 0)
	{
		alSourcef(m_aAudioSources[pAudio->m_nSourceID], AL_GAIN, pAudio->m_fGain);
	}
}