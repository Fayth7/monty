#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define QUEUE 1
#define STAACK 0
#define DELIMS " \n\t\a\b"
#define STACK_MODE 0

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @queue: 1 if the stack is a queue, 0 if it's a stack
 * @data: Additional data member for the stack
 * @top: Current top index of the stack
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
int queue;
int data;
int top;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/** PRIMARY INTERPRETER FUNCTIONS */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void process_file(FILE *file);
void free_stack(stack_t **stack);
#endif /* _MONTY_H_ */
