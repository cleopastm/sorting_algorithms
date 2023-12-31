#include "sort.h"

/**
 * getMax - Get the maximum element from an array
 * @array: The array to find the maximum from
 * @size: The size of the array
 * Return: The maximum element
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return (max);
}

/**
 * countingSort - Sort an array using counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The current exponent for sorting
 */
void countingSort(int *array, size_t size, int exp)
{
    int *output, *count;
    int i;

    output = malloc(sizeof(int) * size);
    count = malloc(sizeof(int) * 10);

    if (output == NULL || count == NULL)
    {
        free(output);
        free(count);
        return;
    }

    for (i = 0; i < 10; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < (int)size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = (int)size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < (int)size; i++)
    {
        array[i] = output[i];
    }

    free(output);
    free(count);
}

/**
 * radix_sort - Sort an array of integers using Radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (array == NULL || size < 2)
    {
        return;
    }

    max = getMax(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, size, exp);
        print_array(array, size);
    }
}

