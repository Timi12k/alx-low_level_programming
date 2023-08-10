#include <stdio.h>
#include <string.h>

/**
 * reverse_string - Reverses a string.
 * @str: The string to be reversed.
 *
 * Return: A pointer to the reversed string.
 */
char *reverse_string(char *str)
{
	int i, j;
	char temp;

	for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

	return (str);
}

/**
 * infinite_add - Adds two infinite numbers represented as strings.
 * @n1: The first number as a string.
 * @n2: The second number as a string.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer r.
 *
 * Return: A pointer to the resulting string if successful, 0 otherwise.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int carry = 0;
	int i = 0;
	int n1_len = strlen(n1);
	int n2_len = strlen(n2);

	/* Check if the result can fit in the buffer */
	if (n1_len > size_r - 1 || n2_len > size_r - 1)
	{
		return (0);
	}

	/* Initialize the result buffer with null terminators */
	for (i = 0; i < size_r; i++)
	{
		r[i] = '\0';
	}

	/* Perform the addition digit by digit */
	i = 0;
	while (i < n1_len || i < n2_len || carry)
	{
		int num1 = i < n1_len ? n1[n1_len - 1 - i] - '0' : 0;
		int num2 = i < n2_len ? n2[n2_len - 1 - i] - '0' : 0;
		int sum = num1 + num2 + carry;

		if (i >= size_r - 1)
		{
			/* Result exceeds buffer size, return 0 */
			return (0);
		}

		r[i] = sum % 10 + '0';
		carry = sum / 10;
		i++;
	}

	/* Reverse the result string before returning */
	reverse_string(r);

	return (r);
}

/**
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char num1[] = "123456789012345678901234567890";
	char num2[] = "987654321098765432109876543210";
	char result[100];

	char *sum = infinite_add(num1, num2, result, sizeof(result));

	if (sum)
	{
		printf("Sum: %s\n", sum);
	}
	else
	{
		printf("Result cannot fit in buffer.\n");
	}

	return (0);
}
