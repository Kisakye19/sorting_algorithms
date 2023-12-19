#include "sort.h"
#include <stdio.h>

/**
 * int_swap - swaps two values in an array
 *
 * @array: data to sort
 * @i: first value
 * @j: second value
 * @size: size of data
 *
 * Return: No Return
 */
void int_swap(int *array, int i, int j, int size)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * l_partition - sorts a l_partition of data in relation to a pivot
 *
 * @array: data to sort
 * @below: Left wall
 * @above: right wall
 * @size: size of data
 *
 * Return: New Pivot
 */
int l_partition(int *array, int below, int above, size_t size)
{
	int i = below, j, pivot  = array[above];

	for (j = below; j <= above; j++)
	{
		if (array[j] < pivot)
		{
			int_swap(array, i, j, size);
			i++;
		}

	}
	int_swap(array, i, above, size);

	return (i);
}

/**
 * l_sort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto l_partition scheme
 *
 * @array: data to sort
 * @below: Left wall
 * @above: right wall
 * @size: size of data
 *
 * Return: No Return
 */
void l_sort(int *array, int below, int above, size_t size)
{
	int p;

	if (below < above)
	{
		p = l_partition(array, below, above, size);
		l_sort(array, below, p - 1, size);
		l_sort(array, p + 1, above, size);
	}
}

/**
 * quick_sort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto l_partition scheme
 *
 * @array: data to sort
 * @size: size of data
 *
 * Return: No Return
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	l_sort(array, 0, size - 1, size);
}
