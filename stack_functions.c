#include "monty.h"

extern stack_t *head;

/**
 * push_to_stack - Adds a node to the top of the stack.
 * @new_node: Pointer to the new node.
 * @ln: Integer representing the line number of the opcode.
 */

void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * display_stack - Prints all nodes in the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void display_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_from_stack - Removes the top node of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void pop_from_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		handle_runtime_error(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * peek_stack - Prints the value at the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void peek_stack(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		handle_runtime_error(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * show_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void show_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		handle_runtime_error(7, line_number);

	printf("%d\n", (*stack)->n);
}
/**
 * remove_top - removes a node from the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void remove_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (stack == NULL || *stack == NULL)
		handle_runtime_error(7, line_number);
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
