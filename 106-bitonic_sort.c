#include "sort.h"
#include <stdio.h>

/**
 * printcheck - print a range
 * @array: The array to print
 * @r1: Less range
 * @r2: Final range
 * Return: Nothing
 */
void printcheck(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
 * int_swap - swap two elements in an array
 * @array: THe array to change the values
 * @i: A index
 * @j: Another index
 * @fstart: Direction of the array
 * Return: Nothing
 */
void int_swap(int *array, int i, int j, int fstart)
{
	int tmp;

	if (fstart == (array[i] > array[j]))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}
/**
 * bitonic_merge - swap the elements to sort
 * @array: Array to sort
 * @start: The start element in the range to sort
 * @size: The size of the range to sort
 * @fstart: Indicate which half are manage
 * @r_size: The size of the all array
 * Return: Nothing
 */
void bitonic_merge(int *array, int start, int size, int fstart, const int r_size)
{
	int k = size, i = start;

	if (size > 1)
	{
		k = size / 2;

		for (i = start; i < start + k; i++)
			int_swap(array, i, i + k, fstart);

		bitonic_merge(array, start, k, fstart, r_size);
		bitonic_merge(array, start + k, k, fstart, r_size);
	}
}
/**
 * _sort - segmentate the array
 * @array: The array to sort
 * @start: The startest element in each range
 * @size: Size of the range to sort
 * @fstart: Indicate which half are manage
 * @r_size: The size of the all array
 * Return: Nothing
 */
void _sort(int *array, int start, int size, int fstart, const int r_size)
{
	int k = size;

	if (size > 1)
	{
		if (fstart == 1)
			printf("Merging [%d/%d] (UP):\n", size, r_size);
		if (fstart == 0)
			printf("Merging [%d/%d] (DOWN):\n", size, r_size);
		printcheck(array, start, start + k - 1);

		k = size / 2;
		_sort(array, start, k, 1, r_size);

		_sort(array, start + k, k, 0, r_size);

		bitonic_merge(array, start, size, fstart, r_size);
		if (fstart == 1)
		{
			printf("Result [%d/%d] (UP):\n", size, r_size);
			printcheck(array, start, start + 2 * k - 1);
		}
		if (fstart == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", size, r_size);
			printcheck(array, start, start + 2 * k - 1);
		}
	}
}
/**
 * bitonic_sort - call the sort function
 * @array: The array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int r_size = (int)size;

	if (size < 2 || !array)
		return;

	_sort(array, 0, (int)size, up, r_size);
}
