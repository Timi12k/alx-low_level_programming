#include <stdio.h>

/**
 * main - Prints all command-line arguments
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i;

	i = 0;
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}

	return (0);
}
