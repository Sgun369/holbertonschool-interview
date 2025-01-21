#include "holberton.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string contains only digits.
 * @str: The string to check
 * Return: 1 if the string is only digits, 0 otherwise
 */
int is_digit(char *str)
{
	int i = 0;

	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/**
 * _strlen - computes the length of a string
 * @str: The sring to measure.
 * Return: The length of the string
 */
int _strlen(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return (len);
}
/**
 * _puts - Prints a string to stdout using _putchar
 * @str: The string to print
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
}
/**
 * mul - Multiplies two nubers repreented as strings.
 * @num1: The first number
 * @num2: The second number
 * Return: A string repreenting the product of the two numbers
 */
char *mul(char *num1, char *num2)
{
	int len1 = _strlen(num1), len2 = _strlen(num2);
	int *result = calloc(len1 + len2, sizeof(int));
	char *product;
	int i, j, carry, n1, n2, sum;

	if (!result)
		exit(98);
	for (i = len1 - 1; i >= 0; i --)
	{
		carry = 0;
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i+ j + 1] = sum % 10;
		}
		result[i + j + 1] += carry;
	}
	product = malloc(len1 + len2 + 1);
	if (!product)
		exit(98);
	i = 0;
	j = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;
	if (i == len1 + len2)
		product[j++] = '0';
	while ( i < len1 + len2)
		product[j++] = result[i++] + '0';
	product[j] = '\0';
	free(result);
	return (product);
}
/**
 * main - Entry point of the program
 * @argc: the number of arrgumets
 * @argv: array of command-line arguments
 * Return: 0 on success, exit with status 98 on error
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;

	if (argc != 3)
	{
		_puts("Error\n");
		exit(98);
	}
	num1 = argv[1];
	num2 = argv[2];
	if (!is_digit(num1) || !is_digit(num2))
	{
		_puts("Error\n");
		exit(98);
	}
	result = mul(num1, num2);
	_puts(result);
	_putchar('\n');
	free(result);
	return (0);
}
