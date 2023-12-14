#include "monty.h"

/**
 * handle_create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon success a pointer to the node. Otherwise NULL.
 */
stack_t *handle_create_node(int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
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
 * handle_free_nodes - Frees nodes in the stack.
 */
void handle_free_nodes(void)
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
 * handle_add_to_queue - Adds a node to the queue.
 * @newNode: Pointer to the new node.
 * @line: line number of the opcode.
 */
void handle_add_to_queue(stack_t **newNode, unsigned int line)
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
	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}
	tempNode->next = *newNode;
	(*newNode)->prev = tempNode;
}
