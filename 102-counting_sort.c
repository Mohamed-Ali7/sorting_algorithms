#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: Is the arry to sort
 * @size: Is the size of the array
 * Return: void
*/

void counting_sort(int *array, size_t size)
{
	int i, k = 0, new_index;
	int *count, *temp_array;

	if (!array || size < 2)
		return;

	temp_array = malloc(sizeof(int) * size);
	if (temp_array == NULL)
		return;

	for (i = 0; i < (int) size; i++)
	{
		if (k < array[i])
			k = array[i];
		temp_array[i] = array[i];
	}

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	for (i = 0; i <= k; i++)
		count[i] = 0;

	for (i = 0; i < (int) size; i++) /*19, 48, 99, 71, 13, 52, 96, 73, 86, 7*/
		count[array[i]]++;

	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];

	print_array(count, k + 1);

	for (i = size - 1; i >= 0; i--)
	{
		new_index = --count[temp_array[i]];
		array[new_index] = temp_array[i];
	}
	free(count);
	free(temp_array);
}
