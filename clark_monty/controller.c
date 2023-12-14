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
/**
 * process_line - Prints all the values of the stack
 * @stack: a pointer to the stack
 * @line: the line number in the monty bytecode file
 * @ln: the line number in the monty bytecode file
 * @len: the line number in the monty bytecode file
 */
void process_line(char *line, size_t len, unsigned int *ln, stack_t **stack)
{
	char *opcode, *arg;
	(void)len;
	opcode = strtok(line, " \t\n");

	if (opcode != NULL && *opcode != '#')
		return;

	arg = strtok(NULL, " \t\n");

	execute_instruction(opcode, arg, *ln, stack);
}

/**
 * execute_instruction - Prints all the values of the stack
 * @arg: a pointer to the stack
 * @ln: the line number in the monty bytecode file
 * @stack: the line number in the monty bytecode file
 * @op: the line number in the monty bytecode file
 */
void execute_instruction(char *op, char *arg, unsigned int ln, stack_t **stack)
{
	if (strcmp(op, "push") == 0)
	{
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}

		push(stack, atoi(arg));
	}
	else if (strcmp(op, "pall") == 0)
	{
		pall(stack, ln);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, op);
		exit(EXIT_FAILURE);
	}

}
/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
