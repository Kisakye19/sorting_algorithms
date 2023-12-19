#include <stdlib.h>
#include "sort.h"
/**
 * c_sort - auxiliary function of radix sort
 *
 * @array: array of data to be sorted
 * @buf: malloc bufer
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: No Return
 */
void c_sort(int *array, int **buf, int size, int lsd)
{
	int i, j, c_size = 10, numb;
	int car_l[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int car_l2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		numb = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				numb = numb / 10;
		numb = numb % 10;
		buf[numb][car_l[numb]] = array[i];
		car_l[numb] += 1;
	}

	for (i = 0, j = 0; i < c_size; i++)
	{
		while (car_l[i] > 0)
		{
			array[j] = buf[i][car_l2[i]];
			car_l2[i] += 1, car_l[i] -= 1;
			j++;
		}
	}

	print_array(array, size);
}
/**
 * csort - auxiliary function of radix sort
 *
 * @array: array of data to be sorted
 * @size: size of data
 * @lsd: Less significant digit
 *
 * Return: No Return
 */
void csort(int *array, int size, int lsd)
{
	int car_l[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, numb, c_size = 10, **buf;

	for (i = 0; i < size; i++)
	{
		numb = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				numb = numb / 10;
		numb = numb % 10;
		car_l[numb] += 1;
	}

	if (car_l[0] == size)
		return;

	buf = malloc(sizeof(int *) * 10);
	if (!buf)
		return;

	for (i = 0; i < c_size; i++)
		if (car_l[i] != 0)
			buf[i] = malloc(sizeof(int) * car_l[i]);


	c_sort(array, buf, size, lsd);

	csort(array, size, lsd + 1);

	for (i = 0; i < c_size; i++)
		if (car_l[i] > 0)
			free(buf[i]);
	free(buf);
}
/**
 * radix_sort - sorts an array of integers in ascending order using the Radix
 * sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
