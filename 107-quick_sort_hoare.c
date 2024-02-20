#include <stdio.h>
#include "sort.h"

int partition(int *arr, int start, int end, int arr_size);
void my_quick_sort(int *arr, int start, int end, int arr_size);

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
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: Is the arry to sort
 * @size: Is the size of the array
 * Return: void
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	my_quick_sort(array, 0, size - 1, size);
}

/**
 * my_quick_sort - Sorts an array of integers in ascending order recursively
 * using the Quick sort algorithm
 *
 * @arr: Is the arry to sort
 * @start: Is the first index of array segment to sort
 * @end: Is the last index of array segment to sort
 * @arr_size: Is the size of the entire array
 * Return: void
*/

void my_quick_sort(int *arr, int start, int end, int arr_size)
{
	int piv;

	if (start < end)
	{
		piv = partition(arr, start, end, arr_size);
		my_quick_sort(arr, start, piv, arr_size);
		my_quick_sort(arr, piv + 1, end, arr_size);
	}
}

/**
 * partition - Puts the pivot of the received array (last element)
 * at it's right plases where all it's right elements is greater than it
 * and left elements are less than it using (Lomuto partition scheme)
 *
 * @arr: Is the arry to sort
 * @start: Is the first index of array segment to sort
 * @end: Is the last index of array segment to sort
 * @arr_size: Is the size of the entire array
 * Return: the new position of the (pivot)
*/

int partition(int *arr, int start, int end, int arr_size)
{
	int pivot = arr[end];
	int i = start - 1;
	int j = end + 1;

	while (i <= j)
	{

		i++;
		while (arr[i] < pivot)
			i++;
		j--;
		while (arr[j] > pivot)
			j--;
		if (i > j)
			return (j);
		if (i != j)
		{
			swap(&arr[j], &arr[i]);
			print_array(arr, arr_size);
		}
	}
	return (j);
}
