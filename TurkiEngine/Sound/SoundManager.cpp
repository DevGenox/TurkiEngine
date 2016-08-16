#include "SoundManager.h"
namespace Turki
{
	SoundManager::SoundManager()
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	}

	SoundManager::~SoundManager()
	{
	}
	bool SoundManager::load(const char* id ,const char* path, const char* type)
	{
		if (type == "Music")
		{
			loadedMus = Mix_LoadMUS(path);
			if (loadedMus == 0)
			{
				std::cout << "Müzik yüklenemedi HATA : " << Mix_GetError() << std::endl;
				return false;
			}

			Musics[id] = loadedMus;
			loadedMus = NULL;
			return true;
		}
		if(type == "Effect")
		{
			loadedChunk = Mix_LoadWAV(path);
			if (loadedChunk == 0)
			{
				std::cout << "Müzik yüklenemedi HATA : " << Mix_GetError() << std::endl;
				return false;
			}

			Chunks[id] = loadedChunk;
			loadedChunk = NULL;
			return true;
		}
		return false;
	}
	void SoundManager::play(const char* id)
	{
		if (Musics[id] != 0)
		{
			loadedMus = Musics[id];
			Mix_VolumeMusic(10);
			Mix_PlayMusic(loadedMus, 1);
		}
		if (Chunks[id] != 0)
		{
			loadedChunk = Chunks[id];
			Mix_PlayChannel(-1, loadedChunk, 0);
		}
	}
}