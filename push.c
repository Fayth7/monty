#include "monty.h"
/**
 * push - Pushes an element to the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @value: Value to be pushed.
 */
void push(stack_t **stack, int value)
{
stack_t *new_node;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->next = *stack;
if (*stack != NULL)
(*stack)->prev = new_node;
new_node->prev = NULL;
*stack = new_node;
}
