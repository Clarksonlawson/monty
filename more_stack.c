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
		handle_error(4);
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
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * handle_add_to_queue - Adds a node to the queue.
 * @newNode: Pointer to the new node.
 * @line: line number of the opcode.
 */
void handle_add_to_queue(stack_t **newNode, __attribute__((unused))unsigned int line)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *newNode;
	(*newNode)->prev = temp;

}
