#include "sort.h"
#include <stdio.h>

void heapify(int *arr, int size, int pos, int original_size);
void build_heap(int *arr, int size);
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
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: Is the arry to sort
 * @size: Is the size of the array
 * Return: void
*/

void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	build_heap(array, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);

	}
}

/**
 * heapify - Heapifies the array which means that it will modify the array to
 * turn it to a complete binary tree
 *
 * @arr: Is the arry to heapify
 * @size: Is the size of the array to heapify
 * @pos: Is the position of the parent parent that will be heapified
 * @original_size: Is the size of the entire array
 * (Only used in print_array() function)
 * Return: void
*/


void heapify(int *arr, int size, int pos, int original_size)
{
	int max = pos;
	int left = pos * 2 + 1;
	int right = pos * 2 + 2;

	if (left < size && arr[left] > arr[max])
		max = left;

	if (right < size && arr[right] > arr[max])
		max = right;

	if (max != pos)
	{
		swap(&arr[pos], &arr[max]);
		print_array(arr, original_size);
		heapify(arr, size, max, original_size);
	}
}

/**
 * build_heap - Heapifies the array n times using heapify function which means
 * that it will modify the array to turn it to a complete binary tree (n) times
 * and (n) = size / 2 - 1 to make sure that the whole array is heapified
 *
 * @arr: Is the arry to heapify
 * @size: Is the size of the array to heapify
 * (In this case it's the size of the entire array)
 * Return: void
*/

void build_heap(int *arr, int size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i, size);
}
