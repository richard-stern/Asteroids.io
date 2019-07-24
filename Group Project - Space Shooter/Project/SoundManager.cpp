#include "SoundManager.h"


SoundManager* SoundManager::Instance = nullptr;

SoundManager::SoundManager(){}


SoundManager::~SoundManager(){
	for(auto& sound : CachedSounds){
		UnloadSound(*(sound.second));
	}
}

Sound& SoundManager::LoadSound(Sound& sound){
	if(sound.data)return sound;
	if(CachedSounds.find(sound.File) != CachedSounds.end()){
		sound.data = CachedSounds[sound.File]->data;
	}
	sound.data = _AM->CreateSound(sound.File);
	return sound;
}

void SoundManager::UnloadSound(Sound& sound){
	if(sound.data)_AM->DestroySound(sound.data);
	sound.data = nullptr;
}

SoundManager* SoundManager::Create(){
	if(Instance)return Instance;
	Instance->_AM = AudioManager::Instance();
	Instance = new SoundManager();
	return Instance;
}

void SoundManager::Destroy(){
	if(Instance){
		delete Instance;
		Instance = nullptr;
	}
}

void SoundManager::PlaySound(int ID){
	if(ID < LoadedSounds.size()){
		LoadedSounds[ID]->data->Play();
	}
}

void SoundManager::PlaySound(Sound& sound){
	LoadSound(sound);
	sound.data->Play();
}

void SoundManager::LoadSounds(std::vector<Sound> files){
	for(Sound& sound : files){
		LoadedSounds.push_back(&LoadSound(sound));
	}
}

void SoundManager::LoadSounds(Sound files[], int amount){
	for(int i = 0; i < amount; ++i){
		LoadedSounds.push_back(&LoadSound(files[i]));
	}
}

void SoundManager::UnloadAllSounds(){
	LoadedSounds.clear();
}

void SoundManager::ClearCache(){
	for(auto& sound : CachedSounds){
		UnloadSound(*(sound.second));
		CachedSounds.erase(sound.first);
	}
}
