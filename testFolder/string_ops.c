#include "monty.h"

/**
 * handle_print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_print_char(stack_t **stack, unsigned int line)
{
	int ascII;

	if (stack == NULL || *stack == NULL)
		handle_string_error(11, line);

	ascII = (*stack)->n;
	if (ascII < 0 || ascII > 127)
		handle_string_error(10, line);
	printf("%c\n", ascII);
}

/**
 * handle_print_str - Prints a string.
 * @stack: Double pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_print_str(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	int ascII;
	stack_t *tempNode;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tempNode = *stack;
	while (tempNode != NULL)
	{
		ascII = tempNode->n;
		if (ascII <= 0 || ascII > 127)
			break;
		printf("%c", ascII);
		tempNode = tempNode->next;
	}
	printf("\n");
}

/**
 * handle_rotl - Rotates the first node of the stack to the bottom.
 * @stack: Double pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_rotl(stack_t **stack, __attribute__((unused)) unsigned int line)
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

/**
 * handle_rotr - Rotates the last node of the stack to the top.
 * @stack: Double pointer pointing to top node of the stack.
 * @line: the line number of of the opcode.
 */
void handle_rotr(stack_t **stack, unsigned int line)
{
	stack_t *tempNode;
	(void)line;

	if (stack == NULL || *stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;

	tempNode = *stack;
	while (tempNode->next != NULL)
		tempNode = tempNode->next;

	tempNode->next = *stack;
	tempNode->prev->next = NULL;
	tempNode->prev = NULL;
	(*stack)->prev = tempNode;
	(*stack) = tempNode;
}
