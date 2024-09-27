#include "monty.h"

/**
 * trim_newline - Removes trailing \n and \r characters from a string.
 * @str: The string to be trimmed.
 *
 * Return: Pointer to the trimmed string.
 */
char *trim_newline(char *str)
{
	size_t len = strlen(str);

	while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r'))
	{
		str[len - 1] = '\0';
		len--;
	}
	return (str);
}
