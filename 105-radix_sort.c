#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm
 *
 * @array: Is the arry to sort
 * @size: Is the size of the array
 * Return: void
*/

void radix_sort(int *array, size_t size)
{
	int max_number = 0, temp_element, new_index;
	int divider = 1, *count, *temp_array;
	size_t i;

	if (!array || size < 2)
		return;
	temp_array = malloc(sizeof(int) * size);
	if (!temp_array)
		return;
	for (i = 0; i < size; i++)
	{
		if (max_number < array[i])
			max_number = array[i];
	}

	count = malloc(sizeof(int) * 10);
	if (!count)
		return;
	for (divider =  1; max_number / divider > 0; divider *= 10)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (i = 0; i < size; i++)
		{
			temp_array[i] = array[i];
			temp_element = (temp_array[i] / divider) % 10;
			count[temp_element]++;
		}
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = size - 1; (int) i >= 0; i--)
		{
			temp_element = (temp_array[i] / divider) % 10;
			new_index = --count[temp_element];
			array[new_index] = temp_array[i];
		}
		print_array(array, size);
	}
	free(temp_array);
	free(count);
}
