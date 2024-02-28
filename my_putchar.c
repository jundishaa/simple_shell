#include "shell.h"

/**
  *_putchar - this is to print the
  *characters to the standard output
  *@c: this is the character that
  *is to printed to the outpou
  *Return: 1 else -1
  *
  */
int _putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
  *print - this code is to write
  *or print the strings to the standard output
  *@text: it is the string
  *that is printed to the standard output
  *Return: the number of bytes
  *printed ( if success) else -1
  *
  *
  */
int print(char *text)
{
	int count = _strlen(text);

	return (write(STDOUT_FILENO, text, count));
}
