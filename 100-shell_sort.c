#include "sort.h"
#include <stdio.h>
/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm
 *
 * @array: Is the arry to sort
 * @size: Is the size of the array
 * Return: void
*/

void shell_sort(int *array, size_t size)
{
	int j, temp = 0;
	size_t i, gap = 0;

	if (!array || size < 2)
		return;
	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap)
			{
				temp = array[j];
				array[j] = array[j + gap];
				array[j + gap] = temp;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
