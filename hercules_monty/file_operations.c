#include "monty.h"
/**
 * handle_open_file - Opens a file
 * @file_name: File to open
 * Return: Returns nothing
 */

void handle_open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name ==NULL || fd == NULL)
	{
		handle_error(2, file_name);
	}
	handle_read_line(fd);
	fclose(fd);
}

/**
 * handle_read_line - reads the file from FD
 * @fd: pointer to the file
 * Return: Nothing
 */
void handle_read_line(FILE *fd)
{
	int line_number, file_format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (line_number = 1; getline(&buffer, &length, fd) != -1; line_number++)
	{
		file_format = handle_parse_line(buffer, line_number, file_format);
	}
	free(buffer);
}

/**
 * handle_parse_line - tokenize each line
 * @buffer: File lines
 * @line_number: Line number
 * @format: Storage format
 * Return: 0 if stack, 1 if Queue
 */
int handle_parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		handle_error(4);
	}
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "queue") == 0)
		return(1);
	if (strcmp(opcode, "stack") == 0)
		return(0);

	handle_find_function(opcode, value, line_number, format);
	return (format);
}

void handle_find_function(char *opcode, char *value, int line, int format)
{
	int i;
	int flag;

	instruction_t function_list[] = {
		{"push", handle_add_to_stack},
		{"pall", handle_print_stack},
		{"pint", handle_print_top},
		{"add", handle_add_nodes},
		{"sub", handle_sub_nodes},
		{"div", handle_div_nodes},
		{"pop", handle_pop_top},
		{"nop", handle_nop},
		{"swap", handle_swap_nodes},
		{"pchar", handle_print_char},
		{"pstr", handle_print_str},
		{"rotl", handle_rotl},
		{"mul", handle_mul_nodes},
		{"mod", handle_mod_nodes},
		{"rotr", handle_rotr},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; function_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, function_list[i].opcode) == 0)
		{
			handle_call_function(function_list[i].f, opcode, value, line, format);
			flag = 0;
		}
	}
	if (flag == 1)
		handle_error(3, line, opcode);
}

/**
 * handle_call_function - calls the function required
 * @func: pointer to the function to call
 * @op: opcode
 * @val: numeric value
 * @line: line number for the instruction
 * @format: Format specifier
 */

void handle_call_function(op_func func, char *op, char *val, int line, int format)
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
		newNode = handle_create_node(atoi(val) * flag);
		if (format == 0)
			func(&newNode, line);
		if (format == 1)
			handle_add_to_queue(&newNode, line);
	}
	else
		func(&head, line);
}
