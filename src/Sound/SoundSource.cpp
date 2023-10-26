#include "SoundSource.h"

Sound::SoundSource::SoundSource(){
	alGenSources(1, &p_Source);
	alSourcef(p_Source, AL_PITCH, p_Pitch);
	alSourcef(p_Source, AL_GAIN, p_Gain);
	alSource3f(p_Source, AL_POSITION, p_Position[0], p_Position[1], p_Position[2]);
	alSource3f(p_Source, AL_VELOCITY, p_Velocity[0], p_Velocity[1], p_Velocity[2]);
	alSourcei(p_Source, AL_LOOPING, p_LoopSound);
	alSourcei(p_Source, AL_BUFFER, p_Buffer);
}

Sound::SoundSource::~SoundSource()
{
	alDeleteSources(1, &p_Source);
}

void Sound::SoundSource::Play(const ALuint buffer_to_play)
{
	if (buffer_to_play != p_Buffer)
	{
		p_Buffer = buffer_to_play;
		alSourcei(p_Source, AL_BUFFER, p_Buffer);
	}

	alSourcePlay(p_Source);

	ALint source_state = AL_PLAYING;
	std::cout << "Playing sound\n";
	while (source_state == AL_PLAYING && alGetError() == AL_NO_ERROR)
	{
		std::cout << "currently playing sound\n";
		alGetSourcei(p_Source, AL_SOURCE_STATE, &source_state);
	}
	std::cout << "Sound stopped\n";
}