#include <stdio.h>

/**
 * print_array - prints the elements of an arrray
 * @array: pointer to the first element of the array
 * @low: starting index of the subarray to print
 * @high: Ending index of the subarray to print
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
	}
	printf("\n");
}
/**
 * recursive_binary - Recursively searches for a value in a sorrted array
 * @array: Pointer to the first element of the array
 * @low: starting index of the subarray
 * @high: Ending index of the subarray
 * @value: value to search for
 * Return: index where value is located, or -1 on failure
 */
int recursive_binary(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	print_array(array, low, high);
	mid = low + (high - low) / 2;
	if (array[mid] == value && (mid == low || array[mid - 1] != value))
		return ((int)mid);

	if (array[mid] >= value)
		return (recursive_binary(array, low, mid, value));
	return (recursive_binary(array, mid + 1, high, value));
}
/**
 * advanced_binary - searches for a value in a sorted arrray
 * @array: pointer to the first element of the array
 * @size: number of element in the array
 * @value: value to search for
 * Return: index where value is located, or -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (recursive_binary(array, 0, size - 1, value));
}
