#include "main.h"

/**
 * cd_cmd - changes directory
 * @cmd: the directory to change to
 * Return: 0 on success
 */

int cd_cmd(char **cmd)
{
	char *home_dir, *buffer, *buffer2, *buf, *current, *oldpwd;
	size_t size = 100;

	buffer = malloc(sizeof(char) * size);
	if (!buffer)
		return (-1);
	current = getcwd(buffer, size), oldpwd = getenv("OLDPWD");
	if (cmd[1] == NULL)
	{
		home_dir = getenv("HOME");
		if (chdir(home_dir) != 0)
		{
			perror("cd"), free(buffer);
			return (-1);
		}
		setenv("OLDPWD", current, 1), setenv("PWD", home_dir, 1), free(buffer);
		return (0);
	}
	if (strcmp(cmd[1], "-") == 0)
	{
		if (chdir(oldpwd) != 0)
		{
			perror("cd"), free(buffer);
			return (1);
		}
		setenv("OLDPWD", current, 1), setenv("PWD", oldpwd, 1), free(buffer);
		write(STDOUT_FILENO, oldpwd, strlen(oldpwd)), write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	if (chdir(cmd[1]) != 0)
	{
		perror("cd"), free(buffer);
		return (1);
	} setenv("OLDPWD", current, 1);
	buffer2 = malloc(sizeof(char) * size);
	if (!buffer2)
		return (-1);
	buf =  getcwd(buffer2, size), setenv("PWD", buf, 1);
	free(buffer), free(buffer2);
	return (0);
}
