#pragma once

#include <AL/alc.h>
#include <AL/al.h>
#include <stdio.h>
#include <iostream>

namespace Sound
{
	class SoundDevice
	{
	public:
		static SoundDevice *get();

	private:
		SoundDevice();
		~SoundDevice();

		ALCdevice *p_ALDevice;
		ALCcontext *p_ALCContext;
	};
}