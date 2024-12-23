#ifndef SORT_H
#define SORT_H
#include <stddef.h>

void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t root, size_t end);
void build_max_heap(int *array, size_t size);
void swap(int *array, int i, int j);
void print_array(int *array, size_t size);

#endif
