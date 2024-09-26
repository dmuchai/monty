#include "monty.h"

/**
 * open_script - Opens the Monty bytecode file for reading
 * @file_name: Path to the Monty bytecode file
 * Return: void
 */
void open_script(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		handle_error(2, file_name);

	interpret_file(fd);
	fclose(fd);
}

/**
 * interpret_file - Reads and interprets the Monty bytecode file
 * @fd: File pointer to the open Monty bytecode file
 * Return: void
 */
void interpret_file(FILE *fd)
{
	int line_number, mode = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		mode = process_line(buffer, line_number, mode);
	}
	free(buffer);
}

/**
 * process_line - Tokenizes each line to identify the opcode and argument
 * @buffer: Line from the file
 * @line_number: Current line number being processed
 * @mode: Format specifier (0 for stack, 1 for queue)
 * Return: 0 if opcode is "stack", 1 if opcode is "queue"
 */
int process_line(char *buffer, int line_number, int mode)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		handle_error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (mode);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	match_instruction(opcode, value, line_number, mode);
	return (mode);
}

/**
 * match_instruction - executes the corresponding function for an opcode
 * @opcode: The opcode string
 * @value: Argument for the opcode (if any)
 * @ln: Current line number
 * @mode: Format specifier (0 for stack, 1 for queue)
 * Return: void
 */
void match_instruction(char *opcode, char *value, int ln, int mode)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push_to_stack},
		{"pall", display_stack},
		{"pint", show_top},
		{"pop", remove_top},
		{"nop", no_operation},
		{"swap", swap_stack_top},
		{"add", add_stack_nodes},
		{"sub", subtract_stack_nodes},
		{"div", divide_stack_nodes},
		{"mul", multiply_stack_nodes},
		{"mod", mod_stack_nodes},
		{"pchar", display_char},
		{"pstr", display_string},
		{"rotl", rotate_left},
		{"rotr", rotate_right},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			execute_instruction(func_list[i].f, opcode, value, ln, mode);
			flag = 0;
		}
	}
	if (flag == 1)
		handle_error(3, ln, opcode);
}


/**
 * execute_instruction - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @mode: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void execute_instruction(op_func func, char *op, char *val, int ln, int mode)
{
	stack_t *node;
	int sign_flag = 1, i;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			sign_flag = -1;
		}
		if (val == NULL)
			handle_error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				handle_error(5, ln);
		}
		node = new_stack_node(atoi(val) * sign_flag);
		if (mode == 0)
			func(&node, ln);
		else
			push_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
