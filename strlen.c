#include "shell.h"

/**
 * _strlen - return string length
 *
 * @s: string
 *
 * Return: string length
 */
int _strlen(char *s)
{
	int c = 0;

	while (*(s + c) != '\0')
		c++;
	return (c);
}