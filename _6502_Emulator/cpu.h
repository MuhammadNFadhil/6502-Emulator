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
	Byte C : 1;     // Carry Flag
	Byte Z : 1;     // Zero Flag
	Byte I : 1;     // Interrupt Disable
	Byte D : 1;     // Decimal Mode
	Byte B : 1;	    // Break Command
	Byte V : 1;     // Overflow Flag
	Byte N : 1;     // Negative Flag

	void Reset(Memory& memory)
	{
		// Faking the boot up sequence:
		PC = 0xFFFC;		// 
		SP = 0x0100;		// Setting the stack pointer
		C = Z = I = D = B = V = N = 0; // Clearing the flags
		A = X = Y = 0;		// 
		memory.initialize();
	}
};
