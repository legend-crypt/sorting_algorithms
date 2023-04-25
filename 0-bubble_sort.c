#include "sort.h"

/**
 * bubble_sort - sort array using bubble sort algorithms
 *
 * @array: the array to be sorted
 * @size: the number of element in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int temp;
	int swap;
	if (size < 2)
	{
		return;
	}

	for (; i < size; i++)
	{

		for (; j < size - 1 - i; i++)
		{
			swap = 0;
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
			if (swap == 0)
			{
				break;
			}
		}
	}

	
}
