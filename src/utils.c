#include <stdio.h>

#include "bfed/displays.h"
#include "bfed/utils.h"

struct stack stack;

/*
    @brief: Read the input from the user
*/

int read_input(void)
{
	scanf("%d\n", &stack.mem[stack.memloc]);
	return stack.mem[stack.memloc];
}

/*
    @brief: Increment or decrement the memory data
    @param: int memloc
    @param: int direction - 1 for increment, 0 for decrement
*/

void change_memory_value(int index, int iterator)
{
	if(iterator == 0)
	{
		stack.mem[index]--;
	}
	else if(iterator == 1)
	{
		stack.mem[index]++;
	}
}

/*
    @brief: Turn an input to a ASCII character
    @param: int input_to_convert
*/

int int_to_ascii(int input)
{
	return '0' + input;
}