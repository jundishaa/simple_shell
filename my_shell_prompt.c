#include "shell.h"

/**
   *new_prompt -this code is going to
   *start or initialize my new prompt
   *
   *return: void or nothin will returned
   */

void  new_prompt(void)
{
	int w, x, y;
	char *i, *j, *k = "> ";
	char *prompt = NULL;

	i = _getenv("USER");
	j = _getenv("NAME");

if (!i || !j)
    {
        perror("Environment variables not set");
        print("$ ");
        return;
    }
	w = _strlen(i);
	x = _strlen(j);
	y = _strlen(k);

	prompt = malloc(w + x + y + 1);
	if (prompt == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (!i || !j || !prompt)
	{
		free(prompt);
		print("$ ");
		return;
	}

	prompt = _strcpy(prompt, i);
	prompt = _strcat(prompt, "@");
	prompt = _strcat(prompt, j);
	prompt = _strcat(prompt, k);

	print(prompt);

	free(prompt);
}

