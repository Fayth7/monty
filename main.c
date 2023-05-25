#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define STACK_SIZE 1024

void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

int main(int argc, char *argv[])
{
    char *filename;
    char line[256];
    int line_number = 1;
    stack_t *stack = NULL;
    char *opcode;
    char *argument;
    FILE *file;
    int value = 0;
    
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    filename = argv[1];
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", filename);
        return (EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = '\0';

        opcode = strtok(line, " ");
        if (opcode == NULL)
        {
            line_number++;
            continue;
        }

        argument = strtok(NULL, " ");

        if (strcmp(opcode, "push") == 0)
        {
            if (argument == NULL)
            {
                printf("L%d: usage: push integer\n", line_number);
                fclose(file);
                _stack(&stack, line_number);
                return (EXIT_FAILURE);
            }
	    value = atoi(argument);
    push(&stack, value);
    }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(&stack, line_number);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(&stack, line_number);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap(&stack, line_number);
        }
        else
        {
            printf("L%d: unknown instruction %s\n", line_number, opcode);
            _stack(&stack, line_number);
            fclose(file);
            return (EXIT_FAILURE);
        }

        line_number++;
    }

    _stack(&stack, line_number);
    fclose(file);
    return (EXIT_SUCCESS);
}
