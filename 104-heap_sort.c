#include "sort.h"

/**
 * int_swap - swaped 2 values.
 * @array: the array for swap him values.
 * @i: First index
 * @j: Second index
 * @r_size: The size constant for print
 * Return: Nothing
 */
void int_swap(int *array, int i, int j, const int r_size)
{
	int temp;
	(void) r_size;

	if (i != j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, (size_t)r_size);
	}
}

/**
 * largest_heap - Find the largest number btween the layers
 * @array: The array for sort
 * @size: The menor element
 * @i: The largest.
 * @r_size: The size for print in swap
 * Return: Nothing.
 */
void largest_heap(int *array, size_t size, int i, const int r_size)
{
	int largest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		int_swap(array, i, largest, r_size);
		largest_heap(array, size, largest, r_size);
	}
}

/**
 * heap_sort - Call largest while exist layers
 * @array: The array that generate the layers
 * @size: Size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	const int r_size = (const int)size;
	int i;

	if (size < 2 || !array)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		largest_heap(array, size, i, r_size);

	for (i = size - 1; i >= 0; i--)
	{
		int_swap(array, 0, i, r_size);
		largest_heap(array, i, 0, r_size);
	}
}
