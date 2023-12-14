#include "monty.h"

/**
 * handle_mul_nodes - Adds the top two elements of the stack.
 * @stack: Double pointer pointing to top node of the stack.
 * @line: the line number of of the opcode.
 */
void handle_mul_nodes(stack_t **stack, unsigned int line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handle_more_error(8, line, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * handle_mod_nodes - Adds the top two elements of the stack.
 * @stack: double pointer  pointing to top node of the stack.
 * @line: the line number of of the opcode.
 */
void handle_mod_nodes(stack_t **stack, unsigned int line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		handle_more_error(8, line, "mod");


	if ((*stack)->n == 0)
		handle_more_error(9, line);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
