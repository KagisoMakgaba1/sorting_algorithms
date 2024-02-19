#include "sort.h"

void quick_sort(int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);


/**
 * Sorts an array of integers in ascending order using
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
	int i = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (i != j)
				print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}
