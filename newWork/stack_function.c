#include "monty.h"

/**
 * multiply_stackToptwo - multiplies the top two elements of the stack.
 * @stack: Double pointer pointing to top node of the stack.
 * @line: the line number of of the opcode.
 */
void multiply_stackToptwo(stack_t **stack, unsigned int line)
{
	int sumOperation;

	if (stack == NULL)
	{
		handle_more_error(8, line, "mul");
	}
	if (*stack == NULL)
	{
		handle_more_error(8, line, "mul");
	}
	if ((*stack)->next == NULL)
	{
		handle_more_error(8, line, "mul");
	}

	(*stack) = (*stack)->next;
	sumOperation = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sumOperation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * compute_ElemementMode - omputes the rest of the division
 * @stack: double pointer pointing to top node of the stack.
 * @line: the line number of of the opcode.
 */
void compute_ElemementMode(stack_t **stack, unsigned int line)
{
	int sumOperation;

	if (stack == NULL)
	{
		handle_more_error(8, line, "mod");
	}
	if (*stack == NULL)
	{
		handle_more_error(8, line, "mod");
	}
	if ((*stack)->next == NULL)
	{
		handle_more_error(8, line, "mod");
	}

	if ((*stack)->n == 0)
		handle_more_error(9, line);

	(*stack) = (*stack)->next;
	sumOperation = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sumOperation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
