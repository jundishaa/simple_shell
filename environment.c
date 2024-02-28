#include "shell.h"

/**
  *_getenv - this code is used
  *to get the environmental virable
  *@jund: this is the virable name that we find
  *Return: the value of @jund
  *
  *
  */
char *_getenv(const char *jund)
{
	int x = 0, y = 0;

	while (environ[x])
	{
		while (environ[x][y] && *jund)
		{
			if (environ[x][y] != *jund || (environ[x][y] == '='))
				break;
			y++, jund++;
		}

		if (environ[x][y] == '=' && !*jund)
			return ((*(environ + x) + ++y));
		x++;
	}

	return (NULL);
}
