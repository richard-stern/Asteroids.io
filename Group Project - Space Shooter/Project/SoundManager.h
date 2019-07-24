#pragma once
/*
	Author: Christopher-Robin Ebbbinghaus

	Manager to Keep track of all Sounds and is used to Play them;
*/
#include <memory>
#include <vector>
#include <unordered_map>
#include "Audio.h"
#include "AudioManager.h"
#include "Sound.h"

static const Sound Files[] = {
	"./Sounds/Shoot.wav"
};

enum class SoundID{
	undefined = -1,
	shoot = 0
};

class SoundManager{
	SoundManager();
	~SoundManager();

	std::unordered_map<char*, Sound*>CachedSounds;
	std::vector<Sound*> LoadedSounds;

	AudioManager* _AM;

	Sound& LoadSound(Sound&);
	void UnloadSound(Sound&);

public:
	static SoundManager* Instance;
	static SoundManager* Create();
	static void Destroy();

	void PlaySound(int);
	void PlaySound(Sound&);

	void LoadSounds(std::vector<Sound>);
	void LoadSounds(Sound[], int);

	void UnloadAllSounds();
	void ClearCache();
};

