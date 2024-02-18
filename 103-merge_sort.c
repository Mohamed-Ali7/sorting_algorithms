#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void merge(int *arr, int l, int m, int r);
void merge_sort_recursive(int *arr, int l, int r);
/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: Is the arry to sort
 * @size: Is the size of the array
 * Return: void
*/
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	merge_sort_recursive(array, 0, size - 1);
}

/**
 * merge_sort_recursive - Divides the array to smaller sub arrays recursively
 *
 * @arr: Is the arry to be divided
 * @l: Is the start point of the array
 * @r: Is the end point of the array
 * Return: void
*/

void merge_sort_recursive(int *arr, int l, int r)
{
	int m;

	if (l < r)
	{
		m = (l + r) / 2;
		if ((l + r) % 2 == 0)
			m--;
		merge_sort_recursive(arr, l, m);
		merge_sort_recursive(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

/**
 * merge - Merges the divided sub arrays in sorted order
 *
 * @arr: Is the original arry merge into
 * @l: Is the start point of the left array
 * @m: The end point of the left array and the middle point that divides the
 * left array and the right array (m+1) Is the start point of the right array
 * @r: Is the end point of the right array
 * Return: void
*/

void merge(int *arr, int l, int m, int r)
{
	int left_size = m - l + 1;
	int right_size = r - m;
	int i = 0, j = 0, k = l;
	int *left_arr;

	left_arr = malloc(sizeof(int) * left_size);
	for (i = 0; i < left_size; i++)
		left_arr[i] = arr[i + l];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_arr, left_size);
	printf("[right]: ");

	for (i = m + 1; i <= r; i++)
	{
		printf("%d", arr[i]);
		if (i < r)
			printf(", ");
	}
	printf("\n");
	i = 0;
	j = m + 1;
	k = l;
	while (i < left_size && j <= r)
	{
		if (left_arr[i] <= arr[j])
		{
			arr[k] = left_arr[i];
			i++;
		}
		else
		{
			arr[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
		arr[k++] = left_arr[i++];
	while (j <= right_size)
		arr[k++] = arr[j++];

	printf("[Done]: ");
	for (i = l; i <= r; i++)
	{
		printf("%d", arr[i]);
		if (i < r)
			printf(", ");
	}
	printf("\n");
	free(left_arr);
}
