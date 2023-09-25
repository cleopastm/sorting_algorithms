#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

/**
 * bitonic_merge - Merge two halves of the array in the bitonic order.
 * @array: The array to be sorted.
 * @low: The starting index of the left subarray.
 * @count: The size of the subarray to be merged.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
	size_t k = count / 2;
	size_t i;
	int temp;

	for (i = low; i < low + k; i++)
	{
	if ((array[i] > array[i + k]) == dir)
	{
	temp = array[i];
	array[i] = array[i + k];
	array[i + k] = temp;
	}
	}

	bitonic_merge(array, low, k, dir);
	bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sort a bitonic sequence.
 * @array: The array to be sorted.
 * @low: The starting index of the subarray.
 * @count: The size of the subarray.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
	size_t k = count / 2;
	size_t i;

	printf("Merging [%s]: ", dir ? "Ascending" : "Descending");
	for (i = low; i < low + count; i++)
	{
	printf("%d", array[i]);
	if (i < low + count - 1)
	printf(", ");
	}
	printf("\n");

	bitonic_sort_recursive(array, low, k, 1);
	bitonic_sort_recursive(array, low + k, k, 0);

	bitonic_merge(array, low, count, dir);

	printf("Result [%s]: ", dir ? "Ascending" : "Descending");
	for (i = low; i < low + count; i++)
	{
	printf("%d", array[i]);
	if (i < low + count - 1)
	printf(", ");
	}
	printf("\n");
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	bitonic_sort_recursive(array, 0, size, 1);
}


