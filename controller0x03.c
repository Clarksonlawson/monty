#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *c = *stack;

	(void)line_number;

	while (c != NULL && c->n != 0 && (c->n >= 0 && c->n <= 127))
	{
		putchar(c->n);
		c = c->next;
	}

	putchar('\n');
}
/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	last->next = temp;
	temp->prev = last;
	*stack = temp->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
}

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	last->next = temp;
	temp->prev = last;
	*stack = temp->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
}
/**
 * stack_op - Sets the format of the data to a stack (LIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

