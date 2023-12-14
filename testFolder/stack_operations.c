#include "monty.h"

/**
 * handle_add_to_stack - adds new node to stack.
 * @newNode: pointer to the Node
 * @line: line number
 */

void handle_add_to_stack(stack_t **newNode, unsigned int line)
{
	stack_t *tempNode;
	(void)line;

	if (newNode == NULL || *newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tempNode = head;
	head = *newNode;
	head->next = tempNode;
	tempNode->prev = head;
}

/**
 * handle_print_stack - Adds a node to stack
 * @stack: double pointer to stack top
 * @line: line number
 */
void handle_print_stack(stack_t **stack, unsigned int line)
{
	stack_t *tempNode;
	(void)line;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	tempNode = *stack;
	while (tempNode != NULL)
	{
		printf("%d\n", tempNode->n);
		tempNode = tempNode->next;
	}
}
/**
 * handle_pop_top - Removes the last item of stack
 * @stack: double pointer to node
 * @line: line number
 */
void handle_pop_top(stack_t **stack, unsigned int line)
{
	stack_t *tempNode;

	if (stack == NULL || *stack == NULL)
	{
		handle_more_error(7, line);
	}
	tempNode = *stack;
	*stack = tempNode->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tempNode);
}

/**
 * handle_print_top - Prints the top node
 * @stack: double  pointer pointing to top node
 * @line: line number of of the opcode.
 */
void handle_print_top(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
	{
		handle_more_error(6, line);
	}
	printf("%d\n", (*stack)->n);
}
