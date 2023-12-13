#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @n: The value to push onto the stack.
 */
void push(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;


}

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;
	free(temp);

}
/**
 * pall - Prints all the values of the stack
 * @stack: a pointer to the stack
 * @line: the line number in the monty bytecode file
 */

void pall(stack_t **stack, unsigned int line)
{
	stack_t *current = *stack;
	(void)line;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
