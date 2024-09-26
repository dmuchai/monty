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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* File handling functions */
void open_script(char *file_name);
int process_line(char *line_content, int line_number, int mode);
void interpret_file(FILE *file_stream);
int file_line_length(FILE *file_stream);
void match_instruction(char *opcode, char *arg, int line_number, int mode);

/* Stack manipulation functions */
stack_t *new_stack_node(int value);
void release_stack(void);
void display_stack(stack_t **, unsigned int);
void push_to_stack(stack_t **, unsigned int);
void push_to_queue(stack_t **, unsigned int);

/* Operation dispatcher */
void execute_instruction(op_func, char *, char *, int, int);

/* Stack operation functions */
void show_top(stack_t **, unsigned int);
void remove_top(stack_t **, unsigned int);
void no_operation(stack_t **, unsigned int);
void swap_stack_top(stack_t **, unsigned int);

/* Mathematical operations on stack */
void add_stack_nodes(stack_t **, unsigned int);
void subtract_stack_nodes(stack_t **, unsigned int);
void divide_stack_nodes(stack_t **, unsigned int);
void multiply_stack_nodes(stack_t **, unsigned int);
void mod_stack_nodes(stack_t **, unsigned int);

/* String operation functions */
void display_char(stack_t **, unsigned int);
void display_string(stack_t **, unsigned int);
void rotate_left(stack_t **, unsigned int);

/* Error handling */
void handle_error(int error_code, ...);
void handle_runtime_error(int error_code, ...);
void string_error(int error_code, ...);
void rotate_right(stack_t **, unsigned int);

#endif
