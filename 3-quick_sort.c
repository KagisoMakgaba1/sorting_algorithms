#include "sort.h"

void quick_sort(int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap(int *x, int *y);


/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm with Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}


/**
 * quicksort_recursive - Recursively sorts the array using the
 * Quick sort algorithm.
 * @array: The array to be sorted.
 * @low: The starting index of the partition to be sorted.
 * @high: The ending index of the partition to be sorted.
 * @size: The size of the array.
 */

void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index = lomuto_partition(array, low, high, size);

	if (low < high)
	{
		print_array(array, size);

		quicksort_recursive(array, low, pivot_index - 1, size);
		quicksort_recursive(array, pivot_index + 1, high, size);
	}
}


/**
 * lomuto_partition - Lomuto partition scheme for quicksort.
 * @array: The array to be sorted.
 * @low: The starting index of the partition to be sorted.
 * @high: The ending index of the partition to be sorted.
 * @size: The size of the array.
 *
 * Return: The final position of the pivot in the sorted array.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	i++;
	if (array[i] > pivot)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}


/**
 * swap - swaps two element in an array
 * @x: the first value
 * @y: the second value
 */

void swap(int *x, int *y)
{
	if (!x || !y)
		return;

	if (*x != *y)
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}
