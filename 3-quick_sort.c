#include "sort.h"


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
 * @low: the low bound of the array
 * @high: the higher bound of the array
 * Return: the pivot position of the array
 */

int partition(int *array, size_t low, size_t high)
{
	int pivot_value = array[high];
	size_t i;
	size_t j;

	i = low;
	for(j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return i;
}

/**
 * recursive_quick_sort - performs recusive divide and conquer on the partitioned 
 * array
 * @array: the array to be handled
 * @low: the lower bound of the array
 * @high: the higher bound of the array
 */

void recursive_quick_sort(int *array, size_t low, size_t high)
{
	size_t pivot_index;
	if (low < high)
	{	
		pivot_index = partition(array, low, high);
		recursive_quick_sort(array, low, pivot_index - 1);
		recursive_quick_sort(array, pivot_index + 1, high);
	}
	return;
}




/**
 * quick_sort - sort array element in accending order using
 * quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the @array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	recursive_quick_sort(array, 0, size - 1);
	print_array(array, size);
}

