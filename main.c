#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

stack_t *head = NULL;

/**
 * main - Entry point for Monty bytecode interpreter
 * @argc: Number of arguments passed
 * @argv: Array of argument strings
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_script(argv[1]);
	release_stack();
	return (0);
}

/**
 * new_stack_node - Allocates memory for a new stack node
 * @n: The integer value to store in the node
 * Return: Pointer to the new node, or NULL on failure
 */
stack_t *new_stack_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		handle_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * release_stack - Frees the entire stack
 */
void release_stack(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * push_to_queue - Adds a new node to the end of the queue
 * @new_node: Pointer to the new node to add
 * @ln: Line number in the script (unused)
 */
void push_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;
}
