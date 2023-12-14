#include "monty.h"
/**
 * print_stack_string - Prints a string.
 */
void print_stack_string(stack_t **stack)
{
	int asc2;
	stack_t *tempNode;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tempNode = *stack;
	while (tempNode != NULL)
	{
		asc2 = tempNode->n;
		if (asc2 <= 0 || asc2 > 127)
			break;
		printf("%c", asc2);
		tempNode = tempNode->next;
	}
	printf("\n");
}

/**
 * print_ascii_char - Prints the asc2 value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void print_ascii_char(stack_t **stack, unsigned int line)
{
	int asc2;

	if (stack == NULL || *stack == NULL)
		handle_string_error(11, line);

	asc2 = (*stack)->n;
	if (asc2 < 0 || asc2 > 127)
		handle_string_error(10, line);
	printf("%c\n", asc2);
}

/**
 * rotate_first_func - Rotates the first node of the stack to the bottom.
 */
void rotate_first_func(stack_t **stack)
{
	stack_t *tempNode;

	if (stack == NULL || *stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	tempNode = *stack;
	while (tempNode->next != NULL)
		tempNode = tempNode->next;

	tempNode->next = *stack;
	(*stack)->prev = tempNode;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
