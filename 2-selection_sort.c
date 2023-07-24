#include "sort.h"

/**
 * selection_sort - this sorts an array of intergers in order
 * ascending
 * @array: its the array being sorted
 * @size: its size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t ki, me, y;
	size_t tempo;

	if (array == NULL || size < 2)
		return;

	for (ki = 0; ki < size - 1; ki++)
	{
		y = ki;

		for (me = ki + 1; me < size; me++)
		{
			if (array[me] < array[y])
				y = me;
		}
		if (y != ki)
		{
			tempo = array[ki];
			array[ki] = array[y];
			array[y] = tempo;
			print_array(array, size);
		}
	}
}
