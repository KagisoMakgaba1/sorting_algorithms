#ifndef SORT_H
#define SORT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

void quicksort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void swap(int *x, int *y);

void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
bool left_bubble_sort(listint_t **list, listint_t **current);
bool right_bubble_sort(listint_t **list, listint_t **current);
void counting_sort(int *array, size_t size);

void *_calloc(unsigned int nmemb, unsigned int size);
void merge_sort(int *array, size_t size);
void _merge_sort(int *sub_array, int *temp_array, int left, int right);
void _merge(int *sub_array, int *temp_array, int left,
		int midpoint, int right);

void maxHeapify(int *array, size_t size, int idx, size_t n);
void heap_sort(int *array, size_t size);
void swap(int *a, int *b);

int getMax(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);

void bitonic_merge(int *array, size_t low, size_t cnt, int dir);
void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir);
void bitonic_sort(int *array, size_t size);

#endif
