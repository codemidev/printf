#include "shell.h"

/**
 * _strdup - a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 *
 * @String: char pointer to copy
 *
 * Return: a new char pointer
 */
char *_strdup(char *String)
{
	char *string;
	int cLoop;

	if (String == NULL)
		return (NULL);

	string = malloc(sizeof(char) * (_strlen(String) + 1));

	if (string == NULL)
		return (NULL);

	for (cLoop = 0; cLoop < _strlen(String) + 1; cLoop++)
		string[cLoop] = String[cLoop];

	return (string);
}
