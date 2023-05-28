#include <string.h>
#include "monty.h"
#define QUEUE_MODE 1
#define STACK_MODE 0
/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
char *filename;
char line[256];
int line_number = 1;
char *opcode;
char *argument;
FILE *file;
stack_t *stack = NULL;
    
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);

}
filename = argv[1];
file = fopen(filename, "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}

while (fgets(line, sizeof(line), file))
{
line[strcspn(line, "\n")] = '\0';
if (line[0] == '#')
{
line_number++;
continue;
}
opcode = strtok(line, " ");
if (opcode == NULL)
{
line_number++;
continue;
}

argument = strtok(NULL, " ");

if (strcmp(opcode, "push") == 0)
{
int value;
if (argument == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
fclose(file);
return (EXIT_FAILURE);
}
value = atoi(argument);
push(&stack, value);
}
else if (strcmp(opcode, "push") == 0)
{
push(&stack, line_number);
}
else if (strcmp(opcode, "pall") == 0)
{
pall(&stack);
}
else if (strcmp(opcode, "pint") == 0)
{
pint(&stack, line_number);
}
else if (strcmp(opcode, "swap") == 0)
{
swap(&stack, line_number);
}
else if (strcmp(opcode, "pop") == 0)
{
pop(&stack, line_number);
}
else if (strcmp(opcode, "add") == 0)
{
add(&stack, line_number);
}
else if (strcmp(opcode, "nop") == 0)
{
nop(&stack, line_number);
}
else if (strcmp(opcode, "sub") == 0)
{
sub(&stack, line_number);
}
else if (strcmp(opcode, "div") == 0)
{
_div(&stack, line_number);
}  
else if (strcmp(opcode, "mul") == 0)
{
mul(&stack, line_number);
}
else if (strcmp(opcode, "mod") == 0)
{
mod(&stack, line_number);
}
else if (strcmp(opcode, "comments") == 0)
{
comments(&stack, line_number);
}
else if (strcmp (opcode, "pchar") == 0)
{
pchar (&stack, line_number);
}
else if (strcmp(opcode, "pstr") == 0)
{
pstr(&stack, line_number);
}
else if (strcmp(opcode, "rotl") == 0)
{
rotl(&stack, line_number);
}
else if (strcmp(opcode, "rotr") == 0)
{
rotr(&stack, line_number);
}
else if (strcmp(opcode, "stack") == 0)
{
_stack(&stack, line_number);
}
else if (strcmp(opcode, "queue") == 0)
{
queue(&stack, line_number);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
free_stack(&stack);
fclose(file);
exit(EXIT_FAILURE);
}
line_number++;
}
free_stack(&stack);
fclose(file);
exit(EXIT_SUCCESS);
}
