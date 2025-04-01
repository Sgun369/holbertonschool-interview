#include "regex.h"

/**
 * regex_match - check if a pattern matches a sstring
 * @str: The sttring to be matched
 * @pattern: The pattern containing the regex
 * Return: 1 if patttern matche, otherwise 0
 */
int regex_match(char const *str, char const *pattern)
{
	if (!*pattern)
		return (!*str);
	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
			(*str && (*str == *pattern || *pattern == '.') &&
			regex_match(str + 1, pattern)));
	}
	else if (*str && (*str == *pattern || *pattern == '.'))
	{
		return (regex_match(str + 1, pattern + 1));
	}
	return (0);
}
