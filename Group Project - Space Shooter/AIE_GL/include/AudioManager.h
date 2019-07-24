//----------------------------------------------------------------------------------------
// Simple Audio System.
// Author: Richard Stern
// Built on top of libsndfile (v1.0.26) for file I/O and OpenAL to play the sounds.
//----------------------------------------------------------------------------------------
// Usage:
// Create a new sound instance using AudioManager:
//		Audio* myAudio = AudioManager::Instance()->CreateSound("SoundFileName.wav");
//
// Play sound using pointer to Audio class:
//		myAudio->Play();
//
// Stop or pause using:
//		myAudio->Stop();
//		myAudio->Pause();
//
// Destroy sounds via the AudioManager when no longer needed to avoid memory leaks.
//		AudioManager::Instance()->DestroySound(myAudio);
//----------------------------------------------------------------------------------------
// Supported sound file formats: .wav, .ogg, .aif, .au, .flac, .gsm
//----------------------------------------------------------------------------------------
#pragma once

#include "al.h"
#include "alc.h"

class Audio;

//Maximum simultanious sounds, many sound cards only support 16.
#define MAX_SOUNDS 16

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
class AudioManager
{
public:
	//Get the singleton instance.
	static AudioManager *Instance() { return m_pInstance; }

	//Load a new sound file and return a pointer which can be used to control playback.
	Audio* CreateSound(const char* filename);

	//Destroy sound instance and free memory.
	void DestroySound(Audio* pAudio);

protected:
	// Only the "Application" class can create, destroy, and update this class.
	friend class Application;
	static AudioManager* m_pInstance;
	static void Create() { m_pInstance = new AudioManager(); }
	static void Destroy() { delete m_pInstance; }
	void Update();
	
	//Internal functions, for use by sound system only.
	friend class Audio;
	void PlaySoundInternal(Audio* pAudio);
	void StopSoundInternal(Audio* pAudio);
	void PauseSoundInternal(Audio* pAudio);
	bool GetIsPlayingInternal(int nSourceID);
	bool GetIsPausedInternal(int nSourceID);
	void SetPitchInternal(Audio* pAudio);
	void SetGainInternal(Audio* pAudio);

private:
	AudioManager();
	~AudioManager();

	int GetAvailableSource();

	ALCdevice* m_pOpenALDevice;
	ALCcontext* m_pOpenALContext;
	Audio* m_AudioList;
	ALuint m_aAudioSources[MAX_SOUNDS];
};

