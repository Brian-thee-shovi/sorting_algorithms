#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: 1st integer to swap
 * @b: 2nd integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tempo;

	tempo = *a;
	*a = *b;
	*b = tempo;
}

/**
 * shell_sort - this sorts array of int in ascending order
 * @array: array of integers
 * @size: size of array
 * Description: uses the knuth interval sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t fi, ki, me;

	if (array == NULL || size < 2)
		return;

	for (fi = 1; fi < (size / 3);)
		fi = fi * 3 + 1;

	for (; fi >= 1; fi /= 3)
	{
		for (ki = fi; ki < size; ki++)
		{
			me = ki;
			while (me >= fi && array[me - fi] > array[me])
			{
				swap_ints(array + me, array + (me - fi));
				me -= fi;
			}
		}
		print_array(array, size);
	}
}

