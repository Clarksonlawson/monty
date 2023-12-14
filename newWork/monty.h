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
typedef void (*op_func)(stack_t **, unsigned int);

/**Stack ops**/
void freeStackNodes(void);
stack_t *createNewNode(int n);
void printNode_toStack(stack_t **);
void addNode_toStack(stack_t **);
void addNodeToQueue(stack_t **);
void call_OpsFunction(op_func, char *, char *, int, int);
void print_stackTopNode(stack_t **, unsigned int);
void remove_lastStackItem(stack_t **, unsigned int);
void does_nothing(stack_t **);
void swapTopTwo_Elements(stack_t **, unsigned int);

/**File ops**/
void open_montyFile(char *file_name);
int parse_montyFileLines(char *buffer, int line_number, int format);
void read_montyFileLines(FILE *);
int handle_len_chars(FILE *);
void get_correctFunction(char *, char *, int, int);

/**Error functions **/
void handle_error(int err_code, ...);
void handle_more_error(int err_code, ...);
void handle_string_error(int err_code, ...);
void rotate_last_node(stack_t **);
/**string ops**/
void print_ascii_char(stack_t **, unsigned int);
void print_stack_string(stack_t **);
void rotate_first_func(stack_t **);
/**Math Ops **/
void addsNewNodeToStack(stack_t **, unsigned int);
void Subtracts_toTwoNodes(stack_t **, unsigned int);
void divide_topTwoNodes(stack_t **, unsigned int);
void multiply_stackToptwo(stack_t **, unsigned int);
void compute_ElemementMode(stack_t **, unsigned int);

#endif
