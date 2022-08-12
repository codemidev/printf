#include "shell.h"

/**
 * _strncpy - copies a string
 *
 * @dest: char pointer
 * @s: char pointer
 * @limit: number of character
 *
 * Return: string
 */
char *_strncpy(char *dest, char *s, int Limit)
{
	int length, size_s;

	size_s = _strlen(s);

	for (length = 0; length < Limit; length++)
	{
		dest[length] = (length <= size_s) ? s[length] : '\0';
	}

	return (dest);
}
