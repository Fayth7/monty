#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
printf("L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}
