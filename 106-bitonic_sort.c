#include <stdio.h>
#include "sort.h"

void bitonic_sort_recursion(int *arr, int start, int count,
											int direction, int arr_size);
void bitonic_merge(int *arr, int start, int count,
										int direction, int arr_size);

/**
 * swap - Swaps to elements
 * @x: Is the first element to swap
 * @y: Is the second element to swap
 * Return: void
*/
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 *
 * @array: Is the arry to sort
 * @size: Is the size of the array
 * Return: void
*/

void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_recursion(array, 0, size, 1, size);
}

/**
 * bitonic_sort_recursion - Divides the array to smaller sub arrays recursively
 *
 * @arr: Is the arry to be divided
 * @start: Is the start point of the sub array
 * @count: Is the number of elements of the sub array
 * @direction: Is the direction to sort the sub array
 * (1 to sort it in ascending order and 0 to sort it in descending order)
 *
 * @arr_size: Is the size of the original array
 * Return: void
*/

void bitonic_sort_recursion(int *arr, int start, int count,
										int direction, int arr_size)
{
	int k;
	char *dir = "(UP)";

	if (direction == 0)
		dir = "(DOWN)";

	if (count > 1)
	{
		printf("Merging [%d/%d] %s:\n", count, arr_size, dir);
		print_array(arr + start, count);

		k = count / 2;
		bitonic_sort_recursion(arr, start, k, 1, arr_size);
		bitonic_sort_recursion(arr, start + k, k, 0, arr_size);
		bitonic_merge(arr, start, count, direction, arr_size);

		printf("Result [%d/%d] %s:\n", count, arr_size, dir);
		print_array(arr + start, count);
	}
}

/**
 * bitonic_merge - Merges the divided sub arrays in sorted order recursively
 *
 * @arr: Is the sub arry to be merge
 * @start: Is the start point of the sub array
 * @count: Is the number of elements of the sub array
 * @direction: Is the direction to sort the sub array
 * (1 to sort it in ascending order and 0 to sort it in descending order)
 *
 * @arr_size: Is the size of the original array
 * Return: void
*/

void bitonic_merge(int *arr, int start, int count,
									int direction, int arr_size)
{
	int k, i;

	if (count > 1)
	{
		k = count / 2;

		for (i = start; i < start + k; i++)
		{
			if (direction == (arr[i] > arr[k + i]))
			{
				swap(&arr[i], &arr[i + k]);
			}
		}

		bitonic_merge(arr, start, k, direction, arr_size);
		bitonic_merge(arr, start + k, k, direction, arr_size);
	}
}
