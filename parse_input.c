#include "main.h"

/**
 * parse_input - split the input command args and save them to an array
 * @input: input command args
 * @cmd: array to save them to
 *
 * Return: nothing
*/
void parse_input(char *input, char **cmd)
{
	int i = 0;
	char *token, *ptr;
	bool in_quote = false;

	token = strtok_r(input, " \n", &ptr);

	while (token != NULL)
	{
		if (token[0] == '"' || token[0] == '\'')
		{
			in_quote = true;
			while (token[strlen(token) - 1] != token[0] && in_quote)
			{
				cmd[i++] = strdup(token);
				token = strtok_r(NULL, " \n", &ptr);
				if (token == NULL)
				{
					in_quote = false;
					break;
				}
			}
			if (in_quote)
			{
				in_quote = false;
				cmd[i++] = strdup(token);
			}
		}
		else
		{
			cmd[i++] = strdup(token);
		}
		token = strtok_r(NULL, " \n", &ptr);
	}
	cmd[i] = NULL;

}

