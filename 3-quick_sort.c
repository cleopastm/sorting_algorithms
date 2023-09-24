#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort.
 *
 * @array: The array to be partitioned.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * @size: The size of the array.
 *
 * Return: The pivot index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int temp;
    int j; 

    for (j = low; j <= high - 1; j++) 
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    if (i + 1 != high)
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort.
 *
 * @array: The array to be sorted.
 * @low: The lower index of the partition.
 * @high: The higher index of the partition.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

