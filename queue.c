#include "monty.h"


/**
 * queue - Prints the top element without modifying the data structure.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't print, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
