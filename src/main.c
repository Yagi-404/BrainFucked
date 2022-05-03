#include <stdio.h>
#include <string.h>

#define COMMAND_ERROR           0
#define SYNTHAX_ERROR           1
#define FILE_EXT_ERROR          2
#define NEGATIVE_MEM_ADRESS     3
#define ASCII_CHAR_NOT_FOUND    4

int mem[255] = 0;
int memloc = 0;
char func_name[255] = "";

void read()
{
    
}

void change_memory_value(int index, int iterator)
{
    if(iterator = 0)
    {
        mem[index]--;
    }
    else if(iterator = 1)
    {
        mem[index]++;
    }
}

void print(int locator)
{
    printf("%d\n", mem[locator]);
}

int int_to_ascii(int input)
{
    return '0' + input;
}

void print_asASCII(int locator)
{
    printf("%d\n", int_to_ascii(mem[locator]));
}

void print_memory(void)
{
    for(int i = 0; i < 255; i++)
    {
        printf("%d", mem[i]);
    }
}

void how_to_use(int error_type)
{
    if(error_type == COMMAND_ERROR)
    {
        printf("\e[1;1H\e[2J");  // Clear screen
        printf("It seems that you didn't used correcrtly the command.\n");
        printf("USAGE : bfed <OPTIONS> <FILE>\n");
        printf("OPTIONS : No options for the moment.\n");

    } else if(error_type == SYNTHAX_ERROR)
    {
        printf("\e[1;1H\e[2J");  // Clear screen
        printf("The compiler found synthax error.\n");

    } else if(error_type == FILE_EXT_ERROR)
    {
        printf("\e[1;1H\e[2J");  // Clear screen
        printf("The file extension is not correct.\n");
        printf("It should be : <filename>.bfed\n");

    } else if(error_type == NEGATIVE_MEM_ADRESS)
    {
        printf("\e[1;1H\e[2J");  // Clear screen
        printf("The memory adress is negative, wich is illegal.\n");
    }
}

void compile(FILE* file)
{
    do {
        mem[memloc];
        fscanf(file, "%c", &c);

        /*
            DEFAULT BRAINFUCK INTERPRETER
        */

        if(c == '+')
        {
            change_memory_value(memloc, 1);
        }
        else if(c == '-')
        {
            change_memory_value(memloc, 0);
        }
        else if(c == '>')
        {
            memloc++;
        }
        else if(c == '<')
        {
            memloc--;
        }
        else if(c == '.')
        {
            print(memloc);
        }
        else if(c == ',')
        {
            fscanf(file, "%c", &c);
            mem[memloc] = c;
        }
        else if(c == '[')      // TODO : Handle loops
        {
            if(mem[memloc] == 0)
            {
                int counter = 0;
                do {
                    fscanf(file, "%c", &c);
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
            if(mem[memloc] != 0)
            {
                int counter = 0;
                do {
                    fscanf(file, "%c", &c);
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
            if(mem[memloc] <= 64 || mem[memloc] >= 122)
            {
                how_to_use(ASCII_CHAR_NOT_FOUND);
            } else {
                print_asASCII(memloc);
            }
        }
        else if(c == '\"')
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
        }
        else if(c == '\n')      /*    ERROR HANDLING     */
        {
            continue;
        }
        else if(c == '\0')
        {
            break;
        }
        else if(memloc <= 0)
        {
            how_to_use(NEGATIVE_MEM_ADRESS);
            return 1;
        }
        else
        {
            how_to_use(SYNTHAX_ERROR);
        }
    } while (c != EOF);
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
        char filename[255] = agrv[1];
        char extension[255];
        char delimiter = '.';
        char *name = strtoken(filename, delimiter);
        char *extension = strtoken(filename, delimiter);

        if(!strcmp(extension, "bfed")) how_to_use();

        printf("Compiling...\n");
        
        // compile the given file
        compile(fopen(argv[1], "r")); 

        printf("Compiled successfully.\n");

        printf("The final memory is :\n");

        print_memory();
    }

    return 0;
}