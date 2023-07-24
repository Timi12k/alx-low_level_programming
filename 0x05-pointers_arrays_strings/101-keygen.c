#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * generate_password - Generates a random password of given length
 * @length: The length of the password to be generated
 */
void generate_password(int length)
{
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char password[length + 1]; /* +1 for the null terminator '\0' */

	srand(time(NULL)); /* Initialize the random seed using the current time */

	for (int i = 0; i < length; i++)
		password[i] = charset[rand() % (sizeof(charset) - 1)];

	password[length] = '\0'; /* Null-terminate the password string */
	printf("Generated Password: %s\n", password);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	int password_length = 10; /* Set the desired password length here */
	generate_password(password_length);

	return (0);
}
