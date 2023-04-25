#include "sort.h"

/**
 * selection_sort - sort array using selection sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int swap;
	size_t min;
	size_t temp;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		swap = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
				swap = 1;
			}
		}
		if (swap == 0)
		{
			break;
		}
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
		   print_array(array, size);	
		}
	}
}
