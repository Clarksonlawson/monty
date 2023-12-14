#include "monty.h"
/**
 * handle_error - Prints the appropriate error message
 * @err_code: The error code to print using switch
 */

void handle_error(int err_code, ...)
{
	va_list args;
	char *op;
	int line_num;

	va_start(args, err_code);

	switch(err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",va_arg(args, char *));
			break;
		case 3:
			line_num = va_arg(args, int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	handle_free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * handle_more_error - continues to handle error
 * @err_code: Error code to consider
 */
void handle_more_error(int err_code, ...)
{
	va_list args;
	char *op;
	int line_num;

	va_start(args, err_code);
	switch(err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
		case 8:
			line_num = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	handle_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handle_string_error - handles string error
 * @err_code: Error code to handle
 */

void handle_string_error(int err_code, ...)
{
	va_list args;
	int line_num;

	va_start(args, err_code);
	line_num = va_arg(args, int);
	switch(err_code)
	{
		case 10:
			fprintf(stderr,"L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	handle_free_nodes();
	exit(EXIT_FAILURE);
}
