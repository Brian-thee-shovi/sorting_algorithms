#include "sort.h"

/**
 * Lomuto_partition - ment to partition the arrays in lomuto
 * @array: array being sort
 * @low: its lowest index of the array
 * @high: highest index
 * @size: size of array
 * Return: nothing
 */
int Lomuto_partition(int *array, int low, int high, size_t size)
{
	int ki, y, tempo, me;

	me = array[high];
	ki = low - 1;

	for (y = low; y < high; y++)
	{
		if (array[y] < me)
		{
			ki++;
			if (ki != y)
			{
				tempo = array[ki];
				array[ki] = array[y];
				array[y] = tempo;
				print_array(array, size);
			}
		}
	}

	if (array[high] < array[ki + 1])
	{
		tempo = array[ki + 1];
		array[ki + 1] = array[high];
		array[high] = tempo;
		print_array(array, size);
	}
	return (ki + 1);
}
/**
 * quick_recursion - func helper for quick sorting
 * @array: its the array to sort
 * @low: array lowest index
 * @high: highest index of the array
 * @size: size of the array
 * Return: void
 */
void quick_recursion(int *array, int low, int high, size_t size)
{
	int me;

	if (low < high)
	{
		me = Lomuto_partition(array, low, high, size);

		quick_recursion(array, low, me - 1, size);
		quick_recursion(array, me + 1, high, size);
	}
}
/**
 * quick_sort - uses quicksort
 * @array: array being sort
 * @size: size of array being sort
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_recursion(array, 0, size - 1, size);
}


