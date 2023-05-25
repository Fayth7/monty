#include "monty.h"
/**
 * pop - prints the top
 * @head: stack head
 * @line_number: line in stack
 * Return: no return
*/
void pop(stack_t **stack, unsigned int line_number);
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
