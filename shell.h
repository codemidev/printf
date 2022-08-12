#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define ENV_SEPARATOR "="
#define ESCAPE_SEPARATOR "#"
#define PATH_SEPARATOR ":"
#define COMMAND_SEPARATOR ";\n"
#define SEPARATORS " \n"
#define PROMPT "$ "

extern char **environ;

/**
 * struct environment_s - environment variable
 *
 * @name: environment name
 * @value: environment value
 * @next: points to the next node
 */
typedef struct environment_s
{
	char *name;   /* ex: PATH */
	char *value;  /* ex: /bin:/usr/bin */
	char *global; /* PATH=/bin:/usr/bin */
	struct environment_s *next;
} environment_t;

/**
 * struct appData_s - data variable
 *
 * @arguments: argument's array
 * @buffer: buffer
 * @command: command name
 */
typedef struct appData_s
{
	char **arguments;
	char *buffer;
	char *commandName;
	char **commandList;
	char **history;
	char *programName;
	environment_t *env;
} appData_t;

/**
 * struct errorMessage_s - An structure for each error message
 *
 * @ecode: error code
 * @msg: pointer to error message
 * @size: error message length.
 */
typedef struct errorMessage_s
{
	int code;
	char *msg;
} errorMessage_t;

/**
 * struct customCommand_s - struct conversion to function
 *
 * @command: flag string
 * @func: pointer to func
 */
typedef struct customCommand_s
{
	char *commandName;
	void (*func)(appData_t *);
} customCommand_t;

environment_t *_addEnvNodeEnd(
	environment_t **headNode,
	char *global
);
void _addWord(char *word, int *index, char **array);
int _atoi(char *s);
void *_calloc(unsigned int n, unsigned int s);
void _cdHelp(void);
void _changeDirectory(appData_t *d);
void _changeToAnyDirectory(appData_t *d, char *currentDirectory);
void _changeToHomeDirectory(appData_t *d, char *currentDirectory);
void _changeToPreviousDirectory(appData_t *d, char *currentDirectory);
int _checkEndCharacter(char *s);
int _checkEscapeSeparators(char Char, char *escapeSeparators);
int _checkSeparators(char Char, char *s);
char *_cleanString(char *s);
environment_t *_createEnvNode(char *global);
void _ctrlC(int signal);
void _defaultHelp(char *Command);
int _deleteEnvNode(environment_t *h, char *n);
void _prompt(void);
void _env(appData_t *Data);
void _envHelp(void);
void _errorHandler(appData_t *data, int msgCode);
void _execCommand(appData_t *data);
void _exitStatus(appData_t *data);
void _exitHelp(void);
void _freeAppData(appData_t *data);
void _freeCharDoublePointer(char **ptr);
void _freeEnvList(environment_t *headNode);
char *_generateAbsolutePath(char *path, char *commandName);
char *_generateEnvGlobal(char *name, char *value);
void (*_getCustomFunction(char *cmd))(appData_t *);
environment_t *_getenv(environment_t *environ, char *name);
char *_getenvname(char *var);
char *_getenvvalue(char *var);
int _getEnvIndex(environment_t *head, char *name);
environment_t *_getEnvNodeAtIndex(
	environment_t *head,
	unsigned int index
);
environment_t *_getLastEnvNode(environment_t *headNode);
void _getline(appData_t *data);
char *_getword(char *global, int offset, int size);
void _help(appData_t *data);
void _helpHelp(void);
int _inArray(char Char, char *array);
appData_t *_initData(char **argv);
void _initEnvData(appData_t *data);
int _isdigit(char Char);
int _isNumber(char *s);
char *_itoa(int number);
int _listEnvLen(environment_t *head);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_memset(char *s, char b, unsigned int n);
int _nbrLen(int number);
char **_parsingPathEnvironment(appData_t *data);
void _printenv(environment_t *environ);
int _putchar(char c);
int _puts(char *str);
void *_realloc(void *ptr, unsigned int oldSize, unsigned int newSize);
void _setenv(environment_t *environ, char *name, char *value, int overwrite);
void _setenvHelp(void);
void _setEnvironment(appData_t *data);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strconcat(char *s1, char *s2);
char *_strncpy(char *dest, char *s, int limit);
unsigned int _strcspn(char *s, char *deny);
char *_strdup(char *s);
int _strlen(char *s);
char *_strstr(char *haystack, char *needle);
char **_strtow(char *str, char *separators, char *escapeSeparators);
void _unsetenv(appData_t *data, char *name);
void _unsetenvHelp(void);
void _unsetEnvironment(appData_t *d);
char *_which(appData_t *data);
int _wordNumber(char *str, char *separators);

#endif
