#include "monty.h"
#include <string.h>
/**
 * process_file - read and process the contents of a file
*/
void process_file(FILE *file)
{
char line[256];
int line_number = 1;
char *opcode;
char *argument;
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
exit(EXIT_FAILURE);
}
}
else
{
printf("L%d: unknown instruction %s\n", line_number, opcode);
fclose(file);
exit(EXIT_FAILURE);
}
line_number++;
}
}
