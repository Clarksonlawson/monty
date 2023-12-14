#include "monty.h"

/**
 * handle_add_to_stack - adds new node to stack.
 * @newNode: pointer to the Node
 * @line: line number
 */

void handle_add_to_stack(stack_t **newNode, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	temp = head;
	head = *newNode;
	head->next = temp;
	temp->prev = head;
}

/**
 * handle_print_stack - Adds a node to stack
 * @stack: double pointer to stack top
 * @line: line number
 */
void handle_print_stack(stack_t **stack, unsigned int line)
{
	stack_t *temp;
	(void) line;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * handle_pop_top - Removes the last item of stack
 * @stack: double pointer to node
 * @line: line number
 */
void handle_pop_top(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		handle_more_error(7, line);
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * handle_print_top - Prints the top node
 * @stack: double  pointer pointing to top node
 * @line: line number of of the opcode.
 */
void handle_print_top(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
		handle_more_error(6, line);
	printf("%d\n", (*stack)->n);
}
