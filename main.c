#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define STACK_SIZE 1024

int main(int argc, char *argv[])
{
    char *filename;
    char line[256];
    int line_number = 1;
    char *opcode;
    char *argument;
    FILE *file;
  
    
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
                return (EXIT_FAILURE);
            }
	
	}
	    else
        {
            printf("L%d: unknown instruction %s\n", line_number, opcode);
       fclose(file);
            return (EXIT_FAILURE);
        }

        line_number++;
    }

     fclose(file);
    return (EXIT_SUCCESS);
}
