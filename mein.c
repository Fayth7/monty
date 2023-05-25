#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * main - the entry point of a C program
 * @argc: representing the number of command-line arguments passed
 * @char: An array of strings representing the command-line arguments.
 * return: 0
 */
int main(int argc, char *argv[])
{
char *filename;
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
process_file(file);
fclose(file);
return (EXIT_SUCCESS);
}
