#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Gets the maximum value in an array
 * @array: The array to search
 * @size: The size of the array
 * Return: The maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * counting_soer - performs counting sort on the array
 * @array: The array to sort
 * @size: The size of the array
 * @exp: The exponent representing the currrent digit
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	if (!output)
		return;

	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
/**
 * radix_sort - Sorts an array uing the LSD radix sort
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int max = get_max(array, size);

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}
