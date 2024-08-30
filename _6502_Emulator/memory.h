// Normally, the method implementations would be in a .cpp file, but since the memory
// is not really a part of the emulator, I have it contained in a single header file.

#pragma once

#include "common.h"

struct Memory
{
	static constexpr u32 MAX_MEM = 1024 * 64;
	Byte data[MAX_MEM];

	void initialize()
	{
		for (u32 i = 0; i < MAX_MEM; i++)
			data[i] = 0;
	}	

	Byte operator[](u32 address) const
	{
		return data[address];
	}
};
