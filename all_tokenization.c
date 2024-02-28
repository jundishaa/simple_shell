#include "shell.h"

/**
  *no_newline - this removes
  *the new line from the user input
  *@input: the line of command
  *that the user inputs to the program
  *Return: input that have no any new line
  */
char *no_newline(char *input)
{
	char *str = input;

	str = strtok(str, "\n");
	return (str);
}
/**
  *tokinize - tokinize the command line
  *inputted by the user in to array of string
  *@input:this is the input from the user
  *Return: array of tokinized string
  */
char **tokinize(char *input)
{
	char **my_tokens;
	char *tok, *temporary;
	int j;

	if (!input)
		return (NULL);

	my_tokens = malloc(sizeof(char *) * _strlen(input));
	if (!my_tokens)
	{
		perror("hsh");
		return (NULL);
	}

	input = no_newline(input);

	temporary = _strdup(input);
	tok = strtok(temporary, " ");
	for (j = 0; tok; j++)
	{
		my_tokens[j] = _strdup(tok);
		tok = strtok(NULL, " ");
	}
	my_tokens[j] = NULL;

	free(temporary);

	return (my_tokens);
}

/**
  *command_path- to build the path
  *for the command that is inputted from the user
  *@command_name:this is name of the
  *commands or the file that we build the path for it
  *@dir:the directory or path which the command is found in
  *Return: the path
  */

char *command_path(char *command_name, char *dir)
{
	char *path;
	size_t path_len;

	path_len = _strlen(dir) + _strlen(command_name) + 2;
	path = malloc(sizeof(char) * path_len);
	if (!path)
		return (NULL);
	memset(path, 0, path_len);

	path = _strcat(path, dir);
	path = _strcat(path, "/");
	path = _strcat(path, command_name);

	return (path);
}

/**
  *verify_cmd_path - this is to verify if
  *the command is in the path or not
  *@command: the string array tha the user inputted
  *Return: if the path is found (0) and 1 else
  */
int verify_cmd_path(char **command)
{
	char *env_path, *value, *full_path;
	struct stat info;

	env_path = _getenv("PATH");
	value = strtok(env_path, ":");
	while (value)
	{
		full_path = command_path(*command, value);

		if (stat(full_path, &info) == 0)
		{
			*command = _strdup(full_path);
			free(full_path);
			return (0);
		}
		free(full_path);
		value = strtok(NULL, ":");
	}

	return (1);
}

