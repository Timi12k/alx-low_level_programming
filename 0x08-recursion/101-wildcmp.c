#include "main.h"

/**
 * wildcmp_helper - Recursive helper function for wildcmp.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: 1 if strings can be considered identical, 0 otherwise.
 */
int wildcmp_helper(char *s1, char *s2);

/**
 * wildcmp - Compares two strings considering '*' as a wildcard.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: 1 if strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	return (wildcmp_helper(s1, s2));
}

/**
 * wildcmp_helper - Recursive helper function for wildcmp.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: 1 if strings can be considered identical, 0 otherwise.
 */
int wildcmp_helper(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2 || *s2 == '*')
	{
		return ((*s2 == '*') ?
				(wildcmp_helper(s1, s2 + 1) || wildcmp_helper(s1 + 1, s2)) :
				(wildcmp_helper(s1 + 1, s2 + 1)));
	}

	return (0);
}

