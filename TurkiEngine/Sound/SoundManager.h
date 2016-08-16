#pragma once
#include <SDL_mixer.h>
#include <map>
#include <iostream>
namespace Turki {
	class SoundManager
	{
	public:
		SoundManager();
		~SoundManager();
		bool load(const char* id, const char* path, const char* type);
		void play(const char* id);
	private:
		Mix_Music* loadedMus;
		Mix_Chunk* loadedChunk;
		std::map<const char*, Mix_Music*> Musics;
		std::map<const char*, Mix_Chunk*> Chunks;
	};



}