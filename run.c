#include "shell.h"

/**
  *run - this is to run the command that is
  *inputted from the user by creating the new child process
  *@command: the input command from the user
  *@source: source file where the command is found in
  *Return: o (success)
  */
int run(char **command, char *source)
{
	int status;
	pid_t child;

	if (!*command)
		exit(-1);

	child = fork();

	if (child == -1)
	{
		perror("Error");
		exit(-1);
	}

	if (child == 0)
	{
		if (strncmp(command[0], "./", 2) && strncmp(command[0], "/", 1))
			verify_cmd_path(command);

		if (execve(command[0], command, environ) == -1)
		{
			perror(source);
			free_memory_pp(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}

