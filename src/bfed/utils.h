#pragma once

#define COMMAND_ERROR           0
#define SYNTHAX_ERROR           1
#define FILE_EXT_ERROR          2
#define STACK_UNDERFLOW_ERR     3
#define ASCII_CHAR_NOT_FOUND    4
#define STACK_OVERFLOW_ERR      5
#define FILE_NOT_FOUND          6

extern struct stack {
    int mem[255];
    int memloc;
} stack;

int  read_input(void);
void change_memory_value(int index, int iterator);
int  int_to_ascii(int input);