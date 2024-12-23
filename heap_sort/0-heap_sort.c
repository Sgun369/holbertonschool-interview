#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two elements in an array
 * @array: The array
 * @i: Index of the first element
 * @j: Index of the second element
 */
void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * sift_down - Move the element at index i down the heap to maintain heap property
 * @array: The array
 * @size: Size of the heap
 * @i: Index to start sifting down from
 */
void sift_down(int *array, size_t size, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    // Check if left child is larger than root
    if (left < size && array[left] > array[largest])
        largest = left;

    // Check if right child is larger than largest so far
    if (right < size && array[right] > array[largest])
        largest = right;

    // If largest is not root, swap and continue sifting down
    if (largest != i)
    {
        swap(array, i, largest);
        print_array(array, size); // Only print when a swap happens
        sift_down(array, size, largest);
    }
}

/**
 * build_max_heap - Build a max-heap from the input array
 * @array: The array
 * @size: Size of the array
 */
void build_max_heap(int *array, size_t size)
{
    // Start from the last non-leaf node and sift down
    for (size_t i = size / 2; i-- > 0;)
        sift_down(array, size, i);
}

/**
 * heap_sort - Sort an array of integers in ascending order using the Heap Sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    build_max_heap(array, size);

    // One by one extract elements
    for (size_t i = size - 1; i > 0; i--)
    {
        swap(array, 0, i);
        print_array(array, size); // Print array after each relevant swap
        sift_down(array, i, 0);
    }
}


