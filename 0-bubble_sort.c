#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * bubble_sort - sorts my array in ascending order
 * @array: array being sorted
 * @size: its size  of array being sorted
 */
void bubble_sort(int *array, size_t size)
{
	size_t ki, t;
	int tempo;

	/**
	 * the outer fot loop iterates over the array/ it passes
	 * the inner loop iterates only over unsorted array hence
	 * hence y < size - 1 - w
	 */
	if (size < 2)
		return;

	for (ki = 0; ki < size - 1; ki++)
	{
		for (t = 0; t < size - 1 - ki; t++)
		{
			if (array[t] > array[t + 1])
			{
				tempo = array[t];
				array[t] = array[t + 1];
				array[t + 1] = tempo;
				print_array(array, size);
			}
		}
	}
}


