#include "sort.h"
/**
 * selection_sort - sorts a list using selection sort
 *
 * @array: The list to be sorted
 * @size: The size of the list
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min = 0, t = 0;

	if (array == NULL || size == 0)
		return;
	for ( ; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (array[min] == array[i])
			continue;
		t = array[min];
		array[min] = array[i];
		array[i] = t;
		print_array(array, size);
	}
}
