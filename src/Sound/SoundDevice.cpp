#include "SoundDevice.h"

Sound::SoundDevice* Sound::SoundDevice::get()
{
	static SoundDevice* instance = new SoundDevice();
	return instance;
}

Sound::SoundDevice::SoundDevice()
{
	p_ALDevice = alcOpenDevice(NULL);
	if (!p_ALDevice)
	{
		std::cout << "ERROR: Could not open device!\n";
	}

	p_ALCContext = alcCreateContext(p_ALDevice, NULL);
	if (!alcMakeContextCurrent(p_ALCContext))
	{
		std::cout << "ERROR: Could not make context current!\n";
	}


	if(!alcMakeContextCurrent(p_ALCContext))
		std::cout << "ERROR: Could not make context current!\n";

	const ALchar* name = nullptr;
	if (alcIsExtensionPresent(p_ALDevice, "ALC_ENUMERATE_ALL_EXT"))
		name = alcGetString(p_ALDevice, ALC_ALL_DEVICES_SPECIFIER);
	if (!name || alcGetError(p_ALDevice) != AL_NO_ERROR)
		name = alcGetString(p_ALDevice, ALC_DEVICE_SPECIFIER);
	std::cout << "Opened " << name << std::endl;
}

Sound::SoundDevice::~SoundDevice()
{
	if (!alcMakeContextCurrent(nullptr))
		std::cout << "failed to set context to nullptr";

	alcDestroyContext(p_ALCContext);
	if (p_ALCContext)
		std::cout << "failed to unset during close";

	if (!alcCloseDevice(p_ALDevice))
		std::cout << "failed to close sound device\n";
}