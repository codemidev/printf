#include "shell.h"

/**
 * _which - return absolute path of a command
 *
 * @data: app data structure
 *
 * return: absolute path
 */
char *_which(appData_t *data)
{
	char **pathlist, *absolutepath;
	struct stat st;
	int i = 0;

	if (
		data->commandName[0] == '.' &&
		data->commandName[1] == '/' &&
		stat(data->commandName, &st) == 0
	)
		return (data->commandName);

	pathlist = _parsingPathEnvironment(data);

	if (pathlist == NULL)
		return (NULL);

	while (pathlist[i] != NULL)
	{
		absolutepath = _generateAbsolutePath(pathlist[i], data->commandName);

		/* check if absolute path exist */
		if (stat(absolutepath, &st) == 0)
		{
			_freeCharDoublePointer(pathlist);
			return (absolutepath);
		}
		free(absolutepath);
		i++;
	}
	_freeCharDoublePointer(pathlist);

	/* try to find the command */
	if (stat(data->commandName, &st) == 0)
	{
		return (data->commandName);
	}
	else
		_errorHandler(data, 101);

	return (NULL);
}
