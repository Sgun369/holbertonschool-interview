#include "sort.h"
/**
 * print_sub_array -  prints a subarray
 * @array:pointer the array
 * @size:size of the subarray
 */
void print_sub_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
 * merge - merges the left and right subarrays
 * @array:pointer the array
 * @left:pointer to the left subarray
 * @right:pointer to the right subarray
 * @start: start index of the left subarray
 * @mid:index of the mid of the array
 * @end:end index of the right subarray
 */
void merge(int *array, int *left, int *right, size_t start,
size_t mid, size_t end)
{
	size_t i = 0, j  = 0, k = start, n_left = mid - start, n_right = end - mid;

	printf("Merging...\n[left]: ");
	print_sub_array(left, n_left);
	printf("[right]: ");
	print_sub_array(right, n_right);
	while (i < n_left && j < n_right)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < n_left)
		array[k++] = left[i++];
	while (j < n_right)
		array[k++] = right[j++];
	printf("[Done]: ");
	print_sub_array(array + start, end - start);
}
/**
 * merge_sort_rec -sorts an array of integers using
 * the Merge Sort algorithm recursively
 * @array:pointer the array
 * @temp:pointer to the temp array
 * @start:start index of the subarray
 * @end:iend index of the subarray
 */
void merge_sort_rec(int *array, int *temp, size_t start, size_t end)
{
	if (end - start <= 1)
		return;
	size_t mid = start + (end - start) / 2;
	size_t i;

	merge_sort_rec(array, temp, start, mid);
	merge_sort_rec(array, temp, mid, end);
	int *left = temp + start;
	int *right = temp + mid;

	for (i = start; i < mid; i++)
		left[i - start] = array[i];
	for (i = mid; i < end; i++)
		right[i - mid] = array[i];
	merge(array, left, right, start, mid, end);
}
/**
 * merge_sort -sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 * @array:pointer the array
 * @size:size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	int *temp = malloc(size * sizeof(int));

	if (!temp)
		return;
	merge_sort_rec(array, temp, 0, size);
	free(temp);
}
