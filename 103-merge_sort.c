#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * copy - copies data from one bufer to another
 *
 * @source: source bufer
 * @dest: destination bufer
 * @size: size of bufers
 *
 * Return: No Return
 */
void copy(int *source, int *dest, int size)
{
	int i;

	for (i = 0; i < size; i++)
		dest[i] = source[i];
}
/**
 * td_merge - td_merges two sets of data in ascending order
 * but they must already be sorted before hand
 * @array: first set of data
 * @buf: second set of data
 * @belowL: lower range of first set of data
 * @aboveL: upper range of first set of data
 * @belowR: lower range of second set of data
 * @aboveR: upper range of second set of data
 *
 * Return: No Return
 */
void td_merge(int *array, int *buf, int belowL, int aboveL, int belowR, int aboveR)
{
	int i = belowL, j = belowR, k = belowL;

	while (i <= aboveL || j <= aboveR)

		if (i <= aboveL && j <= aboveR)
			if (buf[i] <= buf[j])
				array[k] = buf[i], k++, i++;
			else
				array[k] = buf[j], k++, j++;

		else if (i > aboveL && j <= aboveR)
			array[k] = buf[j], k++, j++;
		else
			array[k] = buf[i], k++, i++;
}
/**
 * printcheck - prints an array in a given range
 *
 * @array: array of data to be print
 * @r1: start of range
 * @r2: end of range
 *
 * Return: No Return
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
 * split_td_merge - recursive function to split_td_merge data into td_merge tree
 *
 * @array: array of data to be split_td_merge
 * @buf: auxiliary array of data for merging
 * @below: below range of data in array
 * @above: above range of data in array
 * @size: size of total data
 *
 * Return: No Return
 */
void split_td_merge(int *array, int *buf, int below, int above, int size)
{
	int mid, tabove, belowL, aboveL, belowR, aboveR;

	if ((above - below) <= 0)
		return;

	mid = (above + below + 1) / 2;
	tabove = above;
	above = mid - 1;

	belowL = below;
	aboveL = above;

	split_td_merge(array, buf, below, above, size);

	below = mid;
	above = tabove;

	belowR = below;
	aboveR = above;

	split_td_merge(array, buf, below, above, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, belowL, aboveL);

	printf("[right]: ");

	printcheck(array, belowR, aboveR);
	td_merge(array, buf, belowL, aboveL, belowR, aboveR);
	copy(array, buf, size);

	printf("[Done]: ");
	printcheck(array, belowL, aboveR);
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	copy(array, buf, size);

	split_td_merge(array, buf, 0, size - 1, size);

	free(buf);
}
