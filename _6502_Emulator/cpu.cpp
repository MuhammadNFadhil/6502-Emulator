#include "cpu.h"

const Byte INST_LDA_IM = 0xA9;

void CPU::reset(Memory &memory) 
{
    // Faking the boot up sequence:
    PC = 0xFFFC;                   //
    SP = 0x0100;                   // Setting the stack pointer
    C = Z = I = D = B = V = N = 0; // Clearing the flags
    A = X = Y = 0;                 //
    memory.initialize();
}

void CPU::execute(u32 cycles, Memory &memory)
{
    while (cycles > 0)
    {
        Byte instruction = memory[PC];
        (void)instruction;
    }
}
