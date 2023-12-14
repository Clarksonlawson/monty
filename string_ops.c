#include "monty.h"

/**
 * handle_print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_print_char(stack_t **stack, unsigned int line)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		handle_string_error(11, line);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		handle_string_error(10, line);
	printf("%c\n", ascii);
}

/**
 * handle_print_str - Prints a string.
 * @stack: Double pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_print_str(stack_t **stack, __attribute__((unused))unsigned int line)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * handle_rotl - Rotates the first node of the stack to the bottom.
 * @stack: Double pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void handle_rotl(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * hanle_rotr - Rotates the last node of the stack to the top.
 * @stack: Double pointer pointing to top node of the stack.
 * @line: the line number of of the opcode.
 */
void handle_rotr(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
