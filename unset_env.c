#include "main.h"

/**
 * _unsetenv - unsets an environmental variable
 *
 * @cmd: array of commands from user input
 * Return: (0) success
 */

int _unsetenv(char **cmd)
{
	int env;

	if (cmd[1] == NULL)
	{
		perror(cmd[0]);
		return (1);
	}
	env = unsetenv(cmd[1]);
	if (env != 0)
	{
		perror(cmd[0]);
		return (1);
	}
	return (0);
}
