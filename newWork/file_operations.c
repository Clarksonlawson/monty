#include "monty.h"
/**
 * open_montyFile - Opens a file
 * @file_name: File to open
 * Return: Returns nothing
 */

void open_montyFile(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		handle_error(2, file_name);
	}
	read_montyFileLines(fd);
	fclose(fd);
}

/**
 * read_montyFileLines - reads the file from FD
 * @fd: pointer to the file
 * Return: Nothing
 */
void read_montyFileLines(FILE *fd)
{
	int line, file_format = 0;
	char *buffer = NULL;
	size_t length = 0;
	int readOps = getline(&buffer, &length, fd);

	for (line = 1; readOps != -1; line++)
	{
		file_format = parse_montyFileLines(buffer, line, file_format);
	}
	free(buffer);
}

/**
 * parse_montyFileLines - tokenize each line
 * @buffer: File lines
 * @line: Line number
 * @format: Storage format
 * Return: 0 if stack, 1 if Queue
 */
int parse_montyFileLines(char *buffer, int line, int format)
{
	char *opcode, *tokenValue;
	const char *delimiter = "\n ";

	if (buffer == NULL)
	{
		handle_error(4);
	}
	opcode = strtok(buffer, delimiter);
	if (opcode == NULL)
		return (format);
	tokenValue = strtok(NULL, delimiter);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	if (strcmp(opcode, "stack") == 0)
		return (0);

	get_correctFunction(opcode, tokenValue, line, format);
	return (format);
}

void get_correctFunction(char *opcode, char *tokenValue, int line, int format)
{
	int i;
	int flag;

	instruction_t operation_functions[] = {
		{"push", addNode_toStack},
		{"pall", printNode_toStack},
		{"pint", print_stackTopNode},
		{"add", addsNewNodeToStack},
		{"sub", Subtracts_toTwoNodes},
		{"div", divide_topTwoNodes},
		{"pop", remove_lastStackItem},
		{"nop", does_nothing},
		{"swap", swapTopTwo_Elements},
		{"pchar", print_ascii_char},
		{"pstr", print_stack_string},
		{"rotl", rotate_first_func},
		{"mul", multiply_stackToptwo},
		{"mod", compute_ElemementMode},
		{"rotr", rotate_last_node},
		{NULL, NULL}};
	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; operation_functions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, operation_functions[i].opcode) == 0)
		{
			call_OpsFunction(operation_functions[i].f, opcode, tokenValue, line, format);
			flag = 0;
		}
	}
	if (flag == 1)
		handle_error(3, line, opcode);
}

/**
 * call_OpsFunction - calls the function required
 * @func: pointer to the function to call
 * @op: opcode
 * @val: numeric tokenValue
 * @line: line number for the instruction
 * @format: Format specifier
 */

void call_OpsFunction(op_func func, char *op, char *val, int line, int format)
{
	stack_t *newNode;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			handle_error(5, line);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				handle_error(5, line);
		}
		newNode = createNewNode(atoi(val) * flag);
		if (format == 0)
			func(&newNode, line);
		if (format == 1)
			addNodeToQueue(&newNode);
	}
	else
		func(&head, line);
}
