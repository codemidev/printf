#include "shell.h"

/**
 * _strcspn - gets the length of a prefix substring.
 *
 * @s: string to search
 * @deny: characters to deny
 *
 * Return: a pointer to the first occurrence of the character c
 *         in the string s, or NULL if the character is not found
 */
unsigned int _strcspn(char *s, char *deny)
{
	unsigned int strL, dL;

	for (dL = 0; deny[dL] != '\0'; dL++)
	{
		for (strL = 0; deny[dL] != s[strL]; strL++)
			if ('\0' == s[strL])
				return (strL);
	}

	return (strL);
}
