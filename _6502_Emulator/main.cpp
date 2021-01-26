#include <stdio.h>
#include <stdlib.h>

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

struct Mem
{
	static constexpr u32 MAX_MEM = 1024 * 64;
	Byte Data[MAX_MEM];

	void Initialize()
	{
		for (u32 i = 0; i < MAX_MEM; i++)
		{
			Data[i] = 0;
		}
	}
};

struct CPU
{
	Word PC; // Program Counter
	Word SP; // Stack Pointer

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

	void Reset(Mem& memory)
	{
		// Faking the boot up sequence:
		PC = 0xFFFC;		// 
		SP = 0x0100;		// Setting the stack pointer
		C = Z = I = D = B = V = N = 0; // Clearing the flags
		A = X = Y = 0;		// 
		memory.Initialize();
	}
};

int main()
{
	Mem mem;
	CPU cpu;
	cpu.Reset(mem);
	return 0;
}