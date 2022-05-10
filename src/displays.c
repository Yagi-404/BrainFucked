#include <stdio.h>

#include "bfed/displays.h"
#include "bfed/utils.h"

struct stack stack;

/*
    @brief: Prints the usage of the program
    @param: int error_code
*/

void how_to_use(int error_type)
{
	if(error_type == COMMAND_ERROR)
	{
		printf("\e[1;1H\e[2J");  // Clear screen
		printf("[err.CMD_ERROR]\n");
		printf("It seems that you didn't used correcrtly the command.\n");
		printf("USAGE : bfed <OPTIONS> <FILE>\n");
		printf("OPTIONS : No options for the moment.\n");

	} else if(error_type == SYNTHAX_ERROR)
	{
		printf("\e[1;1H\e[2J");  // Clear screen
		printf("[err.SYNTHAX_ERROR]\n");
		printf("The compiler found synthax error.\n");

	} else if(error_type == FILE_EXT_ERROR)
	{
		printf("\e[1;1H\e[2J");  // Clear screen
		printf("[err.FILE_EXT_ERROR]\n");
		printf("The file extension is not correct.\n");
		printf("It should be : <filename>.bfed\n");

	} else if(error_type == STACK_UNDERFLOW_ERR)
	{
		printf("\e[1;1H\e[2J");  // Clear screen
		printf("[err.STACK_UNDERFLOW]\n");
		printf("The memory adress is negative, wich is illegal.\n");
	}
	else if(error_type == ASCII_CHAR_NOT_FOUND)
	{
		printf("\e[1;1H\e[2J");  // Clear screen
		printf("[err.ASCII_CHAR_NOT_FOUND]\n");
		printf("The compiler found an ASCII character that is not defined.\n");
	}
	else if(error_type == STACK_OVERFLOW_ERR)
	{
		printf("\e[1;1H\e[2J");  // Clear screen
		printf("[err.STACK_OVERFLOW]\n");
		printf("The memory adress is too high, wich is illegal.\n");
	}
	else if(error_type == FILE_NOT_FOUND)
	{
		printf("\e[1;1H\e[2J");  // Clear screen
		printf("[err.FILE_NOT_FOUND]\n");
		printf("The file you are trying to open doesn't exist.\n");
	}
}

/*
    @brief: Prints the memory
*/

void print_mem(void)
{
	for(int i = 0; i < 255; i++)
	{
		printf("%d", stack.mem[i]);
	}
}

/*
    @brief: Prints the memory as ASCII
    @param: int memloc
*/

void print_asASCII(int locator)
{
	printf("%d\n", int_to_ascii(stack.mem[locator]));
}

/*
    @brief: Prints the memory as number
    @param: int memloc
*/

void print(int locator)
{
    printf("%d\n", stack.mem[locator]);
}