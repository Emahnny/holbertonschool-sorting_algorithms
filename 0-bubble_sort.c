#include "sort.h"
#include <stdbool.h>

/**
 * swap_ints - Swap two integers in an array.
 * @fi: first swapping integer.
 * @si: second swappin integer.
 */
void swap_ints(int *fi, int *si)
{
	int tmp;

	tmp = *fi;
	*fi = *si;
	*si = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
