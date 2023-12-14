#include "monty.h"

/**
 * handle_nop - Does nothing.
 * @stack: double pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}


/**
 * handle_swap_nodes - Swaps the top two elements of the stack.
 * @stack: Double pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_swap_nodes(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handle_more_error(8, line, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * handle_add_nodes - Adds the top two elements of the stack.
 * @stack: DOuble pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_add_nodes(stack_t **stack, unsigned int line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handle_more_error(8, line, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * handle_sub_nodes - Adds the top two elements of the stack.
 * @stack: double  pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_sub_nodes(stack_t **stack, unsigned int line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		handle_more_error(8, line, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * handle_div_nodes - Adds the top two elements of the stack.
 * @stack: Double  pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_div_nodes(stack_t **stack, unsigned int line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handle_more_error(8, line, "div");

	if ((*stack)->n == 0)
		handle_more_error(9, line);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
