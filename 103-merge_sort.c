#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays into one sorted array.
 *
 * @array: The original array.
 * @left: The left subarray.
 * @right: The right subarray.
 * @size: The size of the original array.
 */
void merge(int *array, int *left, int *right, size_t size)
{
    size_t i = 0, j = 0, k = 0;
    size_t size_left = size / 2;
    size_t size_right = size - size_left;

    printf("Merging...\n[left]: ");
    print_array(left, size_left);
    printf("[right]: ");
    print_array(right, size_right);

    while (i < size_left && j < size_right)
    {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    while (i < size_left)
        array[k++] = left[i++];

    while (j < size_right)
        array[k++] = right[j++];

    printf("[Done]: ");
    print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    size_t middle = size / 2;
    int *left;
    int *right;

    if (size < 2 || array == NULL)
        return;

    left = array;
    right = array + middle;

    merge_sort(left, middle);
    merge_sort(right, size - middle);

    merge(array, left, right, size);
}

