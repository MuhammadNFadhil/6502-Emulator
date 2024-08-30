#pragma once

#include "memory.h"

struct CPU
{
	Word PC; // Program Counter
	Byte SP; // Stack Pointer

	// Registers
	Byte A, // Accumulator
		 X, // Index Register
		 Y; // 

	// Status Flags:
	Byte C : 1;
	Byte Z : 1;
	Byte I : 1;
	Byte D : 1;
	Byte B : 1;	
	Byte V : 1;
	Byte N : 1;

	void Reset(Memory& memory)
	{
		// Faking the boot up sequence:
		PC = 0xFFFC;		// 
		SP = 0x0100;		// Setting the stack pointer
		C = Z = I = D = B = V = N = 0; // Clearing the flags
		A = X = Y = 0;		// 
		memory.Initialize();
	}
};
