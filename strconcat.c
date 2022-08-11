#include "shell.h"

/**
 * _strconcat - concatenates two strings.
 *
 * @s1 : char pointer to concatenate
 * @s2 : char pointer to concatenate
 *
 * Return: char pointer concatenated
 */
char *_strconcat(char *s1, char *s2)
{
	char *s;
	int i, j, size;

	if (s1 == NULL)
		s1 = "\0";

	if (s2 == NULL)
		s2 = "\0";

	size = _strlen(s1) + _strlen(s2);
	s = malloc(sizeof(char) * (size + 1));

	if (s == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		s[i] = s1[i];

	for (j = 0; s2[j]; i++, j++)
		s[i] = s2[j];

	s[i] = '\0';

	return (s);
}
