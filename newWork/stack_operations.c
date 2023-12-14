#include "monty.h"

/**
 * addNode_toStack - adds new node to stack.
 * @newNode: pointer to the Node
 * @line: line number
 */

void addNode_toStack(stack_t **newNode)
{
	stack_t *tempNode;

	if (newNode == NULL)
		exit(EXIT_FAILURE);

	if (*newNode == NULL)
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
 * printNode_toStack - Adds a node to stack
 * @stack: double pointer to stack top
 * @line: line number
 */
void printNode_toStack(stack_t **stack)
{
	stack_t *tempNode;

	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}

	tempNode = *stack;
	while (tempNode != NULL)
	{
		printf("%d\n", tempNode->n);
		tempNode = tempNode->next;
	}
}
/**
 * remove_lastStackItem - Removes the last item of stack
 * @stack: double pointer to node
 * @line: line number
 */
void remove_lastStackItem(stack_t **stack, unsigned int line)
{
	stack_t *tempNode;

	if (stack == NULL)
	{
		handle_more_error(7, line);
	}

	if (*stack == NULL)
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
 * print_stackTopNode - Prints the top node
 * @stack: double  pointer pointing to top node
 * @line: line number of of the opcode.
 */
void print_stackTopNode(stack_t **stack, unsigned int line)
{
	if (stack == NULL)
		handle_more_error(6, line);
	if (*stack == NULL)
		handle_more_error(6, line);

	printf("%d\n", (*stack)->n);
}
