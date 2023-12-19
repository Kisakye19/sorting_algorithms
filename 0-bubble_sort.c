#include "sort.h"

/**
 * bubble_sort - c function that uses uses the Buble sort method in an array
 * @array: array of integers to sort
 * @size: the size of the array to be sorted
 * Return: Sorted array
 */
void bubble_sort(int *array, size_t size)
{
size_t lenth = size;
size_t i, tmp = 0;

if (array == NULL || size == 0)
return;
while (lenth > 0)
{
for (i = 0; i < size - 1; i++)
{
if (array[i] > array[i + 1])
{
tmp = array[i + 1];
array[i + 1] = array[i];
array[i] = tmp;
print_array(array, size);
}
}
lenth--;
}
}
