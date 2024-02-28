#include "shell.h"

/**
  *_strdup - this code is to
  *duplicate the given string
  *@str: this is the string that dupplicated
  *Return: duplicated string
  *
  */
char *_strdup(char *str)
{
	int length, k;
	char *dup;

	if (!str)
		return (NULL);

	length = _strlen(str) + 1;
	dup = malloc(length * sizeof(char));
	if (!dup)
		return (NULL);

	for (k = 0; k < length - 1; k++)
		*(dup + k) = *(str + k);

	*(dup + k) = '\0';

	return (dup);
}
