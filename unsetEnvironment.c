#include "shell.h"

/**
 * _unsetEnvironment - unset environment variable
 *
 * @Data: data's structure
 */
void _unsetEnvironment(appData_t *Data)
{
	if (Data == NULL)
		return;

	if (Data->arguments == NULL)
		return;

	if (Data->arguments[1] == NULL)
		return;

	_unsetenv(Data, Data->arguments[1]);
}
