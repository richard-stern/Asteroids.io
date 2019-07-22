//----------------------------------------------------------------------------------------
// Simple Audio System.
// Author: Richard Stern
// Built on top of libsndfile (v1.0.26) for file I/O and OpenAL to play the sounds.
//----------------------------------------------------------------------------------------
// Usage:
// Create a new sound instance using SoundManager:
//		Audio* myAudio = SoundManager::Instance()->CreateSound("SoundFileName.wav");
//
// Play sound using pointer to Audio class:
//		myAudio->Play();
//
// Stop or pause using:
//		myAudio->Stop();
//		myAudio->Pause();
//
// Destroy sounds via the SsundManager when no longer needed to avoid memory leaks.
//		SoundManager::Instance()->DestroySound(myAudio);
//----------------------------------------------------------------------------------------
// Supported sound file formats: .wav, .ogg, .aif, .au, .flac, .gsm
//----------------------------------------------------------------------------------------
#pragma once

#include "al.h"

class SoundManager;

//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
class Audio
{
public:
	//Control playback.
	void Play();
	void Stop();
	void Pause();
	bool GetIsPlaying();
	bool GetIsPaused();

	//Set the sound to loop until it's told to stop.
	void SetLooping(bool bLooping);

	//Change the pitch and tempo of the sound. Positive values only.
	void SetPitch(float fPitch);

	//Change the volumn of the sound. Valid range is 0.0f - 1.0f.
	void SetGain(float fGain);

protected:
	//Only available to the SoundManager.
	friend class SoundManager;
	Audio(SoundManager* pSoundManager, ALuint nBufferID);
	~Audio();
	
	ALuint m_nBufferID;
	int m_nSourceID;
	bool m_bLooping;
	float m_fPitch;
	float m_fGain;
	Audio* m_pNext;

private:
	SoundManager* m_pSoundManager;
};