#pragma once
#include <AL/al.h>
#include <vector>
#include <sndFile/sndfile.h>
#include <inttypes.h>
#include <AL\alext.h>

namespace Sound
{
	class SoundBuffer
	{
	public:
		static SoundBuffer *get();

		ALuint addSoundEffect(const char *filename);
		bool removeSoundEffect(const ALuint &bufferID);

	private:
		SoundBuffer();
		~SoundBuffer();

		std::vector<ALuint> p_SoundEffectBuffers;
		;
	};
}