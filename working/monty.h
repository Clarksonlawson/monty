#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *head;
typedef void(*op_func)(stack_t **, unsigned int);

/**Stack ops**/
void handle_free_nodes(void);
stack_t *handle_create_node(int n);
void handle_print_stack(stack_t **, unsigned int);
void handle_add_to_stack(stack_t **, unsigned int);
void handle_add_to_queue(stack_t **, unsigned int);
void handle_call_function(op_func, char *, char *, int, int);
void handle_print_top(stack_t **, unsigned int);
void handle_pop_top(stack_t **, unsigned int);
void handle_nop(stack_t **, unsigned int);
void handle_swap_nodes(stack_t **, unsigned int);

/**File ops**/
void handle_open_file(char *file_name);
int handle_parse_line(char *buffer, int line_number, int format);
void handle_read_line(FILE *);
int handle_len_chars(FILE *);
void handle_find_function(char *, char *, int, int);

/**Error functions **/
void handle_error(int err_code, ...);
void handle_more_error(int err_code, ...);
void handle_string_error(int err_code, ...);
void handle_rotr(stack_t **, unsigned int);
/**string ops**/
void handle_print_char(stack_t **, unsigned int);
void handle_print_str(stack_t**, unsigned int);
void handle_rotl(stack_t **, unsigned int);
/**Math Ops **/
void handle_add_nodes(stack_t **, unsigned int);
void handle_sub_nodes(stack_t **, unsigned int);
void handle_div_nodes(stack_t **, unsigned int);
void handle_mul_nodes(stack_t **, unsigned int);
void handle_mod_nodes(stack_t **, unsigned int);

#endif
