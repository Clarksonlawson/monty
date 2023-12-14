#include "monty.h"

/**
 * div - Divides the second top element of the stack by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int divisor = (*stack)->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = ((*stack)->next)->n / divisor;
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next)->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
