#include "sort.h"
#include <stddef.h>

/**
 * swap - swap the position of the array element
 * @x: the position of one array to be swaped with @y
 * @y: the postion of the element to be swaped with @x
 */

void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}


/**
 * partition - partition the @array for recursive sort
 * @size: the size of `@array` to be sorted
 * @array: the array to be sorted
 * @low: the low bound of the array
 * @high: the higher bound of the array
 * Return: the pivot position of the array
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot_value;
	int i;
	int j;

	i = low;
	pivot_value = array[high];
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}

	}
	swap(&array[i], &array[high]);
	if (i != j)
		print_array(array, size);
	return (i);
}


/**
 * quick_recursion - performs recursive divide and conquer on the array
 * @array: the array we sorting
 * @low: the lower bound of the array
 * @high: the higher bound of the array
 * @size: of the array
 */

void quick_recursion(int *array, int low, int high, int size)
{
	int pivot;

	if (low < high)
	{

		pivot = partition(array, low, high, size);
		quick_recursion(array, low, (pivot - 1), size);
		quick_recursion(array, (pivot + 1), high, size);
	}
}

/**
 * quick_sort - sort array using lomoto quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	quick_recursion(array, 0, size - 1, size);
}
