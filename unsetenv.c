#include "shell.h"

/**
 * _unsetenv - unset environment variable
 *
 * @data: data structure
 * @name: environment name
 */
void _unsetenv(appData_t *data, char *name)
{
	_deleteEnvNode(data->env, name);
}
