#define _POSIX_C_SOURCE 200809L

#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char *opcode;
	char *arg;

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

		opcode = strtok(line, " \t\n");

		if (opcode == NULL || *opcode == '#')
			continue;

		arg = strtok(NULL, " \t\n");

		if (strcmp(opcode, "push") == 0)
		{
			if (arg == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				free(line);
				/*free_stack(&stack); */
				return (EXIT_FAILURE);
			}

			push(&stack, atoi(arg));
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free(line);
			/*free_stack(&stack); */
			return (EXIT_FAILURE);
		}
	}

	fclose(file);
	free(line);
	/*free_stack(&stack); */
	return (EXIT_SUCCESS);
}
