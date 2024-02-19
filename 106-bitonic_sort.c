#include "sort.h"

/**
 * bitonic_merge - Helper function to perform bitonic merge
 * @array: Array to be sorted
 * @low: Starting index of the subarray
 * @cnt: Size of the subarray
 * @dir: Sorting direction (UP or DOWN)
 */
void bitonic_merge(int *array, size_t low, size_t cnt, int dir)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;
        size_t i;

        printf("Merging [%lu/%lu] (%s):\n", cnt, cnt, (dir == 1) ? "UP" : "DOWN");
        print_array(array + low, cnt);

        for (i = low; i < low + k; ++i)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;

                printf("Result [2/%lu] (%s):\n", cnt, (dir == 1) ? "UP" : "DOWN");
                print_array(array + low, cnt);
            }
        }

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive function to perform Bitonic sort
 * @array: Array to be sorted
 * @low: Starting index of the subarray
 * @cnt: Size of the subarray
 * @dir: Sorting direction (UP or DOWN)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);

        bitonic_merge(array, low, cnt, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    int dir = 1;

    if (size > 1)
    {
        printf("Merging [%lu/%lu] (UP):\n", size, size);
        print_array(array, size);

        bitonic_sort_recursive(array, 0, size, dir);
    }
}
