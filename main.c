#define _POSIX_C_SOURCE 200809L

#include "monty.h"
/**
 * handle_error - Prints all the values of the stack
 * @s: a pointer to the stack
 * @l: the line number in the monty bytecode file
 * @f: the line number in the monty bytecode file
 * @m: the line number in the monty bytecode file
 * @ln: the line number in the monty bytecode file
 */
void handle_error(FILE *f, char *l, stack_t *s, const char *m, unsigned int ln)
{
	fprintf(stderr, "%s%d: %s\n", m, ln, "Error: ");
	fclose(f);
	free(l);
	free_stack(&s);
	exit(EXIT_FAILURE);
}
/**
 * parse_and_execute - Prints all the values of the stack
 * @line: a pointer to the stack
 * @stack: the line number in the monty bytecode file
 * @f: the line number in the monty bytecode file
 * @ln: the line number in the monty bytecode file
 */
void parse_and_execute(FILE *f, char *line, stack_t **stack, unsigned int *ln)
{
	char *opcode, *arg;


	while (*line == ' ')
		line++;

	opcode = strtok(line, " \t\n");

	if (*line == '#' || *line == '\n' || *line == '\0')
		return;

	if (opcode == NULL || *opcode == '#')
		return;

	arg = strtok(NULL, " \t\n");

	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL)
		{
			handle_error(f, line, *stack, "L", *ln);
		}

		push(stack, atoi(arg));
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, *ln);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, *ln);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, *ln);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, *ln);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, *ln);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, *ln);
	}
	else if (strcmp(opcode, "div") == 0)
	{
		div_op(stack, *ln);
	}
	else if (strcmp(opcode, "sub") == 0)
	{
		sub(stack, *ln);
	}
	else if (strcmp(opcode, "mod") == 0)
	{
		mod(stack, *ln);
	}
	else if (strcmp(opcode, "pchar") == 0)
	{
		pchar(stack, *ln);
	}
	else if (strcmp(opcode, "pstr") == 0)
	{
		pstr(stack, *ln);
	}
	else if (strcmp(opcode, "mul") == 0)
	{
		mul(stack, *ln);
	}
	else if (strcmp(opcode, "rotl") == 0)
	{
		rotl(stack, *ln);
	}
	else if (strcmp(opcode, "rotr") == 0)
	{
		rotr(stack, *ln);
	}
	else if (strcmp(opcode, "stack") == 0)
	{
		stack_op(stack, *ln);
	}
	else if (strcmp(opcode, "queue") == 0)
	{
		queue(stack, *ln);
	}
	else
	{
		handle_error(f, line, *stack, "L", *ln);
	}
}
/**
 * main - entry Entry point
 * @argc: a pointer to the stack
 * @argv: the line number in the monty bytecode file
 * Return: return the value
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		parse_and_execute(file, line, &stack, &line_number);
	}

	fclose(file);
	free(line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
