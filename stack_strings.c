#include "monty.h"

/**
 * display_char - Prints the Ascii value at the top of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: number of of the opcode.
 */
void display_char(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (stack == NULL || *stack == NULL)
		string_error(11, line_number);

	ascii_value = (*stack)->n;
	if (ascii_value < 0 || ascii_value > 127)
		string_error(10, line_number);
	printf("%c\n", ascii_value);
}

/**
 * display_string - Prints a string from the stack
 * @stack: pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void display_string(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	int ascii_value;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ascii_value = temp->n;
		if (ascii_value <= 0 || ascii_value > 127)
			break;
		printf("%c", ascii_value);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotate_left - Rotates the top node of the stack to the bottom.
 * @stack: pointer pointing to top node of the stack.
 * @line_number: Line number of the opcode.
 */
void rotate_left(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotate_right - Rotates the last node of the stack to the top.
 * @stack: Pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void rotate_right(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
