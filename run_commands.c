#include "main.h"

/**
 * run_commands - run the commands
 * @input: input command args
 * @env: environs
 * @argv: args list
 *
 * Return: nothing
*/
int run_commands(char *input, char **env, char **argv)
{
	char *cmd[50], *path;
	int exec_status;

	if (input[0] == '\0')
	{
		return (0);
	} parse_input(input, cmd);
	if (strcmp(cmd[0], "env") == 0)
	{
		print_env(env);
		return (0);
	}
	if (strcmp(cmd[0], "cd") == 0)
	{
		cd_cmd(cmd);
		return (0);
	}
	if (strcmp(cmd[0], "setenv") == 0)
	{
		_setenv(cmd);
		return (0);
	}
	if (strcmp(cmd[0], "unsetenv") == 0)
	{
		_unsetenv(cmd);
		return (0);
	}
	if (strcmp(cmd[0], "exit") == 0)
		handle_exit(input, cmd, argv);
	path = get_path(cmd[0], env);
	if (path == NULL)
	{
		free_input(cmd);
		perror(argv[0]);
		return (0);
	}
	free_input(cmd);
	cmd[0] = path;
	exec_status = _execve(path, cmd, env, argv, input);
	return (exec_status);
}
