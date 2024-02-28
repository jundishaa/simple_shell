#include "shell.h"

/**
  *cmp - this code check if there
  *is one string in another
  *@str1: this is the string to be searched
  *@str2: and this is the string being searched for
  *Return: 1 (if found) or 0
  */
int cmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
		if (*str1++ != *str2++)
			return (0);

	return (*str2 == '\0');
}
/**
  *free_memory_p - this frees the memory of ponters
  *@pointer: this is the pointer to be free
  *
  */
void free_memory_p(char *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}

	pointer = NULL;
}
/**
  * _isalpha - this code checks if
  *a characters is a letter
  *@a: this is the characters to be checked
  *Return: 1 if letter else 0
  */
int _isalpha(char a)
{
	if ((a >= 48) && (a <= 57))
		return (FALSE);

	return (TRUE);
}

/**
  *_atoi - this code converts string to an enteger
  *@s: this the string converted to int
  *
  *Return: an integer
  *
  */
int _atoi(char *s)
{
	int str_len, j = 0, FLAG = 0, y = 0, number = 0, my_digit;

	for (str_len = 0; s[str_len] != '\0'; str_len++)
		;

	while (j < str_len && FLAG == 0)
	{
		if (s[j] == '-')
			++y;

		if (s[j] >= 48 && s[j] <= 57)
		{
			my_digit = s[j] - '0';
			if (y % 2)
				my_digit = -my_digit;
			number = number * 10 + my_digit;
			FLAG = 1;
			if (s[j + 1] < 48 || s[j + 1] > 57)
				break;
			FLAG = 0;
		}
		j++;
	}
	if (FLAG == 0)
		return (0);

	return (number);
}
/**
  *free_memory_pp - free the memory of the double pointer
  *@pointer: that double pointer to free
  *
  *
  */
void free_memory_pp(char **pointer)
{
	char **temporary;

	for (temporary = pointer; *temporary != NULL; temporary++)
		free_memory_p(*temporary);

	free(pointer);
}
