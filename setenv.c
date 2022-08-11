#include "shell.h"

/**
 * _setenv - set environment value
 *
 * @Environ: environment linked list
 * @Name: environment name
 * @Value: environment value
 * @Overwrite: overwrite
 */
void _setenv(
	environment_t *Environ,
	char *Name,
	char *Value,
	int Overwrite
) {
	environment_t *envNode;
	char *tmp;

	if (Name == NULL || Value == NULL)
		return;

	envNode = _getenv(Environ, Name);

	if (envNode == NULL)
	{
		tmp = _generateEnvGlobal(Name, Value);
		_addEnvNodeEnd(&Environ, tmp);
		free(tmp);
	}
	else if (Overwrite == 1)
	{
		free(envNode->value);
		envNode->value = _strdup(Value);
	}
}
