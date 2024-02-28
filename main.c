#include "shell.h"
/**
  *main - this is the main interface of the user
  *@argc: unused for now in this function
  *@argv: command line arguments passed
  *Return:always 0
  */
int main(int argc __attribute__((unused)), char *argv[])
{
	int (*builtin)(char **, int, char *);
	char **inp_words;
	char *imput = NULL;
	size_t length = 0;
	ssize_t read_bytes;
	int prev_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			new_prompt();
		read_bytes = getline(&imput, &length, stdin);
		if (read_bytes == -1)
		{
			free(imput);
			continue;
		}
		imput = no_newline(imput);
		inp_words = tokinize(imput);
		if (!inp_words || !inp_words[0])
		{
			free(imput);
			continue;
		}
		builtin = look_builtins(inp_words);
		if (builtin)
		{
			prev_status = builtin(inp_words, prev_status, argv[0]);
		}
		else
		{
			prev_status = run(inp_words, argv[0]);
		}
		if (inp_words)
		{
		free_memory_pp(inp_words);
		}
		free(imput);
	}
	return (0);
}
