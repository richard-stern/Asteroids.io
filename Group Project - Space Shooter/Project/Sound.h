#pragma once
/*
	Author: Christopher-Robin Ebbinghaus

	Class to Keep Track of Sounds.
*/
#include <memory>
#include "Audio.h"

struct Sound{
	char* File;
	Audio* data = nullptr;

	Sound(char* File){
		this->File = File;
	}
	
	Sound(char* File, Audio* audio){
		this->File = File;
		data = audio;
	}


	bool operator ==(Sound other){
		return !strcmp(File, other.File);
	}
};