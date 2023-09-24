#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array.
 *
 * @array: The array.
 * @i: Index of the first element.
 * @j: Index of the second element.
 */
void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * sift_down - Moves the element at index 'idx' down to its proper position
 * in a max-heap.
 *
 * @array: The array representing the max-heap.
 * @size: The size of the heap.
 * @idx: The index of the element to be sifted down.
 * @original_size: The original size of the array for printing purposes.
 */
void sift_down(int *array, size_t size, int idx, size_t original_size)
{
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < (int)size && array[left] > array[largest])
        largest = left;

    if (right < (int)size && array[right] > array[largest])
        largest = right;

    if (largest != idx)
    {
        swap(array, idx, largest);
        print_array(array, original_size);
        sift_down(array, size, largest, original_size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             Heap Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i, size);

    for (i = size - 1; i > 0; i--)
    {
        swap(array, 0, i);
        print_array(array, size);
        sift_down(array, i, 0, size);
    }
} 

