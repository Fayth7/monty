#include "monty.h"

/**
 * pop - Pops the top element from the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void pop(stack_t **stack, unsigned int line_number)
{
  stack_t *temp;
      if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop, stack is empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}
