#include "shell.h"

/**
 * _setEnvironment - set environment variable
 *
 * @Data: data's structure
 */
void _setEnvironment(appData_t *Data)
{
	if (Data == NULL)
		return;

	if (Data->arguments == NULL)
		return;

	if (Data->arguments[1] == NULL || Data->arguments[2] == NULL)
		return;

	_setenv(Data->env, Data->arguments[1], Data->arguments[2], 1);
}
