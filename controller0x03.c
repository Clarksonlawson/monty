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
