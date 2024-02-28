#include "shell.h"

/**
  *_strcmp - this code is to compares two strings
  *@str1: the first string
  *@str2: the second string
  *Return: if equal (0), str1<str2
  *(negetive) else positive
  */
int _strcmp(char *str1, char *str2)
{
	int a;

	for (a = 0; str1[a]; a++)
		if (str1[a] != str2[a])
			return (str1[a] - str2[a]);

	return (0);
}
/**
  *_strlen - the code is intended
  *to get the length of given string
  *@s:string that is given
  *Return: intended length
  *
  */
int _strlen(const char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;

	return (x);
}

/**
  *_strcpy - the code copies the contents of one
  *string to the other string in the given destination
  *@target: target strijg
  *@source: original or source string
  *Return: the target or copied string
  *
  */
char *_strcpy(char *target, const char *source)
{
	char *temp_str = target;

	while (*source)
		*temp_str++ = *source++;

	*temp_str = '\0';

	return (target);
}
/**
  *_strstr - this finds the first
  *occerence of sustring within given string
  *@haystack: this is the string to search in
  *@needle: the string to search for
  *Return: first character of @needle or null
  */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		if ((*haystack == *needle) && cmp(haystack, needle))
			return (haystack);
		haystack++;
	}

	return (NULL);
}
/**
  *_strcat - this code is used to concatinate the string
  *@target: the target string
  *@source: the source
  *Return: target or concatenated string
  */
char *_strcat(char *target, const char *source)
{
	int len_target, j = 0;

	len_target = _strlen(target);

	while (source[j])
		target[len_target++] = source[j++];
	target[len_target] = '\0';

	return (target);
}

