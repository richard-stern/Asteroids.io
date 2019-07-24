#include "Audio.h"
#include "AudioManager.h"
#include <memory>

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
Audio::Audio(AudioManager* pSoundManager, ALuint nBufferID)
{
	m_pSoundManager = pSoundManager;
	m_nBufferID = nBufferID;
	m_nSourceID = -1;
	m_pNext = nullptr;
	m_bLooping = false;
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
Audio::~Audio()
{
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void Audio::Play()
{
	m_pSoundManager->PlaySoundInternal(this);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void Audio::Stop()
{
	m_pSoundManager->StopSoundInternal(this);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void Audio::Pause()
{
	m_pSoundManager->PauseSoundInternal(this);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
bool Audio::GetIsPlaying()
{
	return m_pSoundManager->GetIsPlayingInternal(m_nSourceID);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
bool Audio::GetIsPaused()
{
	return m_pSoundManager->GetIsPausedInternal(m_nSourceID);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void Audio::SetLooping(bool bLooping)
{
	m_bLooping = bLooping;
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void Audio::SetPitch(float fPitch)
{
	m_fPitch = fPitch;

	if(m_nSourceID >= 0)
		m_pSoundManager->SetPitchInternal(this);
}

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void Audio::SetGain(float fGain)
{
	m_fGain = fGain;

	if (m_nSourceID >= 0)
		m_pSoundManager->SetGainInternal(this);
}