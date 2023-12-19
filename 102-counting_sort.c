#include "sort.h"
#include <stdio.h>
/**
 * _bigest -  Give me the largest number in a array of integers
 * @array: The Int array
 * @size: Size of array
 * Return: The largest number
 */
int _bigest(int *array, size_t size)
{
	size_t i;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < array[i])
			k = array[i];
	}

	return (k);
}
/**
 * mem_set -  Create a integer array and set each space in 0
 * @size: Size of array
 * Return: The integer array
 */
int *mem_set(int size)
{
	int *copy = NULL;
	int i;

	copy = malloc((size) * sizeof(int));

	for (i = 0; i < size; i++)
		copy[i] = 0;

	return (copy);
}
/**
 * counting_sort - sort an array with the counting sort algorithm
 * @array: The Int array
 * @size: Size of array
 * Return: The sorted list
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int k = 0;
	int *copy = NULL, *count = NULL;

	if (size < 2)
		return;
	/*Know the largest number in the array*/
	k = _bigest(array, size);
	/*Make the help array*/
	copy = mem_set(k + 1);
	if (!copy)
		return;
	/*Set the values for sorting*/
	for (i = 0; i < size; i++)
		for (j = 0; (int)j < k + 1; j++)
			if ((int)j == array[i])
				copy[j] += 1;
	/*Modificate the count in the array*/
	for (i = 0; (int)i < k; i++)
		copy[i + 1] = copy[i] + copy[i + 1];
	print_array(copy, k + 1);
	/*Create the sort array*/
	count = malloc(size * sizeof(int));
	if (!count)
	{
		free(copy);
		return;
	}

	for (i = 0; i < size; i++)
	{
		count[copy[array[i]] - 1] = array[i];
		copy[array[i]] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = count[j];

	free(count);
	free(copy);
}
