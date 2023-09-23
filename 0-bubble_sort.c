#include "sort.h"

/**
 * quick_sort - Sorts an array using the Quick sort algorithm in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_partition(array, size, 0, size - 1);
}

/**
 * sort_partition - Recursively sorts partitions in the array.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @first: The index of the first element in the partition.
 * @last: The index of the last element in the partition.
 */
void sort_partition(int *array, int size, int first, int last)
{
	int pivot;

	if (first < last)
	{
		pivot = get_pivot_index(array, size, first, last);

		if (pivot - first > 1)
			sort_partition(array, size, first, pivot - 1);

		if (last - pivot > 1)
			sort_partition(array, size, pivot + 1, last);
	}
}

/**
 * swap - Swaps two elements in the array.
 *
 * @array: A pointer to the array of integers.
 * @first_index: The index of the first element to swap.
 * @second_index: The index of the second element to swap.
 */
void swap(int *array, int first_index, int second_index)
{
	int temp;

	temp = array[first_index];
	array[first_index] = array[second_index];
	array[second_index] = temp;
}

/**
 * get_pivot_index - Determines the index for the next pivot in the sublist.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @first: The index of the first element in the sublist.
 * @last: The index of the last element in the sublist.
 *
 * Return: The index for the new pivot.
 */
int get_pivot_index(int *array, size_t size, int first, int last)
{
	int pivot = last;
	int left = first;
	int new_pivot = first - 1;

	for (; left < last; left++)
	{
		if (array[left] <= array[pivot])
		{
			new_pivot++;
			if (new_pivot != left)
			{
				swap(array, new_pivot, left);
				print_array(array, size);
			}
		}
	}

	if (new_pivot + 1 != last)
	{
		swap(array, new_pivot + 1, last);
		print_array(array, size);
	}

	return (new_pivot + 1);
}

