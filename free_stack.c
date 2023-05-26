#include "monty.h"

/**
 * free_stack - Free the stack.
 * @stack: Double pointer to the stack.
 */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *temp;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    *stack = NULL;
}
