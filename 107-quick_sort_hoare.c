#include "sort.h"

/**
 * int_swap - swaps two values in an array
 *
 * @array: data to sort
 * @i: first value
 * @j: second value
 *
 * Return: No Return
 */
void int_swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * partition - sorts a partition of data in relation to a pivot
 *
 * @array: data to sort
 * @below: Left wall
 * @above: right wall
 * @size: size of data
 *
 * Return: New Pivot
 */
int partition(int *array, int below, int above, size_t size)
{
	int i, j, pivot = array[above];

	for (i = below, j = above; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (i);
		int_swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * quicksort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 *
 * @array: data to sort
 * @below: Left wall
 * @above: right wall
 * @size: size of data
 *
 * Return: No Return
 */
void quicksort(int *array, int below, int above, size_t size)
{
	int p;

	if (below < above)
	{
		p = partition(array, below, above, size);
		quicksort(array, below, p - 1, size);
		quicksort(array, p, above, size);
	}
}

/**
 * quick_sort_hoare -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Hoare partition scheme
 *
 * @array: data to sort
 * @size: size of data
 *
 * Return: No Return
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
