#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @fi: First integer to swap.
 * @si: Second integer to swap.
 */
void swap_ints(int *fi, int *si)
{
	int tmp;

	tmp = *fi;
	*fi = *si;
	*si = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 * Description: Prints an array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
