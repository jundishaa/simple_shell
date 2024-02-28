#include "shell.h"
/**
  *find_builtin - this code is intended to check if
  *the command is normally a builtin command
  *@cmd:this is the command given
  *Return: @cmd in array
  */
builtin_s find_builtin(char *cmd)
{
	builtin_s my_builtins[] = {
		{"exit", exit_func},
		{"env", env_func},
		{NULL, NULL}
	};

	int j;

	for (j = 0; my_builtins[j].cmd; j++)
		if (_strcmp(my_builtins[j].cmd, cmd) == 0)
			return (my_builtins[j]);

	return (my_builtins[j]);
}
/**
  *look_builtins - this code looks
  *if the command is built in command
  *@cmd: command and its arguments
  *Return: function executed null else
  *
  */
int (*look_builtins(char **cmd))(char **, int, char *)
{
	builtin_s d = find_builtin(cmd[0]);

	if (d.cmd)
		return (d.f);

	return (NULL);
}
/**
  *exit_func - this code is for built in exit comand
  *@cmd:array of the command
  *@prev_status: status code
  *@source:the source in which @cmd found
  *Return: status code by user
  */
int exit_func(char **cmd, int prev_status, char *source)
{
	int j = 0;

	if (!cmd[1])
	{
		free_memory_pp(cmd);
		exit(prev_status);
	}

	while (cmd[1][j])
	{
		if (_isalpha(cmd[1][j]) && cmd[1][j] != '-')
		{
			print(source);
			print(": ");
			print(cmd[0]);
			print(": ");
			print("invalid number: ");
			print(cmd[1]);
			_putchar('\n');
			return (1);
		}

		j++;
	}

	prev_status = _atoi(cmd[1]);
	free_memory_pp(cmd);

	exit(prev_status);
}
/**
  *env_func - this code is built in
  *env command implementation code
  *@cmd: this is env command
  *@source: source of @cmd
  *@prev_status: this is the status code in environ
  *Return: 0 on success
  */
int env_func(char **cmd, int prev_status, char *source)
{
	int j;

	(void) cmd;
	(void) prev_status;
	(void) source;

	for (j = 0; environ[j]; j++)
	{
		print(environ[j]);
		_putchar('\n');
	}
	return (0);
}

