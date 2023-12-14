#include "monty.h"
/**
 * createNewNode - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon success a pointer to the node. Otherwise NULL.
 */
stack_t *createNewNode(int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		handle_error(4);
	}
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->n = n;
	return (newNode);
}
/**
 * freeStackNodes - Frees nodes in the stack.
 */
void freeStackNodes(void)
{
	stack_t *tempNode;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tempNode = head;
		head = head->next;
		free(tempNode);
	}
}
/**
 * addNodeToQueue - Adds a node to the queue.
 * @newNode: Pointer to the new node.
 * @line: line number of the opcode.
 */
void addNodeToQueue(stack_t **newNode)
{
	stack_t *tempNode;

	if (newNode == NULL || *newNode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}
	tempNode = head;
	while (tempNode->next != NULL)
		tempNode = tempNode->next;

	tempNode->next = *newNode;
	(*newNode)->prev = tempNode;
}
/**
 * divide_topTwoNodes - Adds the top two elements of the stack.
 * @stack: Double  pointer pointing to top node of the stack.
 * @line: line number of of the opcode.
 */
void divide_topTwoNodes(stack_t **stack, unsigned int line)
{
	int sumOperation;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handle_more_error(8, line, "div");

	if ((*stack)->n == 0)
		handle_more_error(9, line);
	(*stack) = (*stack)->next;
	sumOperation = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sumOperation;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
