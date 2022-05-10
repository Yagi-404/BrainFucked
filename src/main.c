#include <stdio.h>
#include <string.h>

#include "bfed/displays.h"
#include "bfed/utils.h"

struct stack stack;

void compile(FILE* file)
{
	{   // create a context 
		// it will delete everything after the end of the context
	
		char c;
	
		while(c != '!') {
			fscanf(file, "%c", &c);

			if(stack.memloc > 255)    how_to_use(STACK_OVERFLOW_ERR);
			else if(stack.memloc < 0) how_to_use(STACK_UNDERFLOW_ERR);

			/*
				DEFAULT BRAINFUCK INTERPRETER
			*/

			if(c == '+')
			{
				change_memory_value(stack.memloc, 1);
			}
			else if(c == '-')
			{
				change_memory_value(stack.memloc, 0);
			}
			else if(c == '>')
			{
				stack.memloc++;
			}
			else if(c == '<')
			{
				stack.memloc--;
			}
			else if(c == '.')
			{
				print(stack.memloc);
			}
			else if(c == ',')
			{
				read_input();
			}
			else if(c == '[')      // TODO : Handle loops
			{
				if(stack.mem[stack.memloc] == 0)
				{
					int counter = 0;
					do {
						//fscanf(file, "%c", &c);
						if(c == '[')
						{
							counter++;
						}
						else if(c == ']')
						{
							counter--;
						}
					} while(counter != 0);
				}
			}
			else if(c == ']')
			{
				if(stack.mem[stack.memloc] != 0)
				{
					int counter = 0;
					do {
						//fscanf(file, "%c", &c);
						if(c == '[')
						{
							counter--;
						}
						else if(c == ']')
						{
							counter++;
						}
					} while(counter != 0);
				} else
				{
					continue;
				}
			}
			else if(c == '#')       /* ASCII */
			{
				if(stack.mem[stack.memloc] <= 64 || stack.mem[stack.memloc] >= 122)
				{
					how_to_use(ASCII_CHAR_NOT_FOUND);
				} else {
					print_asASCII(stack.memloc);
				}
			}
			/*else if(c == '\"')
			{
				int count = 0;
				do {
					fscanf(file, "%c", &c);
					if(c == '\"')
					{
						break;
					}
					func_name[count] = c;
					count++;
				} while(c != '\"');
			}*/
			else if(c == '\n')      /*    ERROR HANDLING     */
			{
				continue;
			}
			else if(c == '\0')
			{
				break;
			}
			else
			{
				how_to_use(SYNTHAX_ERROR);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	printf("BrainFucked Compiler v0.1\nWritten by: Yagi_404\n\n");

	if (argc < 2)
	{
		printf("NO INPUT FILE\nCOMPILATION FAILED\n");

		how_to_use(COMMAND_ERROR);

		return 1;
	}
	else
	{
		printf("\e[1;1H\e[2J");  // Clear screen

		printf("Verification of the file...\n");
		
		// the file name will be argv[1]

		/*char extension[255];
		char delimiter = '.';
		char *name = strtoken(argv[1], delimiter);
		char *p_extension = strtoken(argv[1], delimiter);

		if(!strcmp( extension, "bfed")) how_to_use(FILE_EXT_ERROR);*/

		printf("Compiling...\n");
		
		// compile the given file
		compile(fopen(argv[1], "r")); 

		printf("Compiled successfully.\n");

		// close the file

		fclose(fopen(argv[1], "r"));

		printf("The final memory is :\n");

		print_mem();
	}

	return 0;
}