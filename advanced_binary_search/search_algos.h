#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H


#include <stddef.h>
void print_array(int *array, size_t low, size_t high);
int recursive_binary(int *array, size_t low, size_t high, int value);
int advanced_binary(int *array, size_t size, int value);
#endif
