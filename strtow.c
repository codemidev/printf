#include "shell.h"

/**
 * _strtow - splits a string into words
 *
 * @string: char pointer
 * @separators: separators
 * @escapeSeparators: escaping separators
 *
 * Return: word array
 */
char **_strtow(char *str, char *separators, char *escapeSeparators)
{
	int cLoop = 0, cLoop1 = 0, wordSize = 0, word_number = 0, size = 0;
	char *word = NULL, **words = NULL, character;

	if (str == NULL)
		return (NULL);

	size = _strlen(str);

	if (str == NULL || !str || word_number == 0)
		return (NULL);

	words = _calloc(sizeof(char *), (word_number + 1));

	if (words == NULL)
		return (NULL);

	for (cLoop = 0; cLoop <= size && cLoop1 < word_number; cLoop++)
	{
		character = str[cLoop];
		if (_checkEscapeSeparators(character, escapeSeparators))
			break;
		if (!_checkSeparators(character, separators))
			wordSize++;
		else
			if (wordSize > 0)
			{
				word = _getword(str, cLoop - wordSize, wordSize);
				_addWord(word, &cLoop1, words);
				wordSize = 0;
			}
	}
	words[cLoop1] = NULL;

	return (words);
}