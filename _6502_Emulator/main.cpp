#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

int main()
{
	Memory mem;
	CPU cpu;
	cpu.reset(mem);
	return 0;
}