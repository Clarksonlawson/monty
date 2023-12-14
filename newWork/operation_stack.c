#include "monty.h"
/**
 * does_nothing - Does nothing.
 * @stack: double pointer pointing to top node of the stack.
 */
void does_nothing(stack_t **stack)
{
	(void)stack;
}
/**
 * swapTopTwo_Elements - Swaps the top two elements of the stack.
 * @stack: Double pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void swapTopTwo_Elements(stack_t **stack, unsigned int line)
{
	stack_t *tempNode;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handle_more_error(8, line, "swap");
	tempNode = (*stack)->next;
	(*stack)->next = tempNode->next;
	if (tempNode->next != NULL)
		tempNode->next->prev = *stack;
	tempNode->next = *stack;
	(*stack)->prev = tempNode;
	tempNode->prev = NULL;
	*stack = tempNode;
}
/**
 * addsNewNodeToStack - Adds the top two elements of the stack.
 * @stack: DOuble pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void addsNewNodeToStack(stack_t **stack, unsigned int line)
{
	int sumOperation;

	if (stack == NULL || *stack == NULL)
		handle_more_error(8, line, "add");
	if ((*stack)->next == NULL)
	{
		handle_more_error(8, line, "add");
	}

	(*stack) = (*stack)->next;

	sumOperation = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sumOperation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * Subtracts_toTwoNodes - Subtracts the top two elements of the stack.
 * @stack: double  pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void Subtracts_toTwoNodes(stack_t **stack, unsigned int line)
{
	int sumOperation;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		handle_more_error(8, line, "sub");

	(*stack) = (*stack)->next;
	sumOperation = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sumOperation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
