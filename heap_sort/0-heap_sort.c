#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - sorts an array of integers in ascending order
 * @array: array of integers
 * @size:size of the array
 * @root: the root of the heap
 * @end: the boundary of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t higher = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < end && array[left] > array[higher])
		higher = left;
	if (right < end && array[right] > array[higher])
		higher = right;
	if (higher != root)
	{
		int tmp = array[root];

		array[root] = array[higher];
		array[higher] = tmp;
		print_array(array, size);
		sift_down(array, size, higher, end);
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size:size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		int tmp = array[0];

		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
