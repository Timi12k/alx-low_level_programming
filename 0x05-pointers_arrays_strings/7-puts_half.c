#include "main.h"
#include <stdio.h>

/**
* _strlen - Returns the length of a string
* @str: Pointer to the string
* Return: The length of the string
*/
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
* puts_half - Prints half of a string
* @str: Pointer to the string
*/
void puts_half(char *str)
{
	int len = _strlen(str);
	int start_index;

	if (len % 2 == 0)
		start_index = len / 2;
	else
		start_index = (len - 1) / 2 + 1;

	while (str[start_index] != '\0')
	{
		putchar(str[start_index]);
		start_index++;
	}

	putchar('\n');
}
