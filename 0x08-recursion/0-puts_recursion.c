#include "main.h"

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');	/* Print a new line when the end of the string is reached */
		return;
	}

	_putchar(*s);	/* Print the current character */
	_puts_recursion(s + 1);	/* Move to the next character and call the function recursively */
}
