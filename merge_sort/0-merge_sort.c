#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays into a sorted arrray
 * @array: The original array
 * @left: left subarray
 * @right: right subarray
 * @size_l: size of left subarray
 * @size_r: size of right subarray
 */
void merge(int *array, int *left, int *right, size_t size_l, size_t size_r)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((size_l + size_r) * sizeof(int));

	if (!temp)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_l);
	printf("[right]: ");
	print_array(right, size_r);

	while (i < size_l && j < size_r)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}
	while (i < size_l)
		temp[k++] = left[i++];
	while (j < size_r)
		temp[k++] = right[j++];

	for (i = 0; i < (size_l + size_r); i++)
		array[i] = temp[i];

	printf("[Done]:");
	print_array(array, size_l + size_r);
	free(temp);
}
/**
 * merge_sort_recursive - recursively plits and sorts the array
 * @array: The array to be sorted
 * @size: size of the array
 */
void merge_sort_recursive(int *array, size_t size)
{
	if (size < 2)
		return;

	size_t mid = size / 2;
	int *left = array;
	int *right = array + mid;

	merge_sort_recursive(left, mid);
	merge_sort_recursive(right, size - mid);
	merge(array, left, right, mid, size - mid);
}
/**
 * merge_sort - sorts an array using merge sort algorithme
 * @array: the array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_recursive(array, size);
}
