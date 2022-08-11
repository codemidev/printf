#include "shell.h"

/**
 * _wordnumber - returns word number
 *
 * @str: char pointer
 * @separators: separators
 *
 * return: word number
 */
int _wordnumber(char *s, char *separators)
{
	int cloop = 0, count = 0;

	while (s[cloop] != '\0')
	{
		if (
			(
				_inArray(s[cloop], separators) != 1 ||
				s[cloop] != '\0'
			 ) &&
			(
				_inArray(s[cloop + 1], separators) == 1 ||
				s[cloop + 1] == '\0'
			)
		)
			count++;
		cloop++;
	}

	return (count);
}
