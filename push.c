#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define STACK_SIZE 1024

void push(stack_t **stack, int value)
{
stack_t *new_node;
if (*stack == NULL)
{
*stack = malloc(sizeof(stack_t));
if (*stack == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}
(*stack)->n = value;
(*stack)->next = NULL;
return;
}
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->next = *stack;
*stack = new_node;
}
