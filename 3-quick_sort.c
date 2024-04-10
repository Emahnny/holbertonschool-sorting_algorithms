#include "sort.h"


/**
 * swap - Function that swaps integers in array.
 *
 * @array: The array of integers.
 * @i: Index of integer to swap.
 * @j: Indez of integer tpo swap.
 */

void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];

	array[i] = array[j];

	array[j] = temp;
}



/**
 * lomutoPartition - Function that partition an array using lomuto scheme.
 *
 * @array: The array of integers.
 * @low: Low index of the partition.
 * @high: High index of the partition.
 * @size: Size of the array.
 *
 * Return: Size of array.
 */

int lomutoPartition(int *array, int low, int high, size_t size)
{
	int pvt = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pvt)
		{
			i++;
			swap(array, i, j);
			if (i != j)
			{
				print_array(array, size);
			}
		}
	}
	swap(array, i + 1, high);

	if (i + 1 != high)
	{
		print_array(array, size);
	}

	return (i + 1);
}



/**
 * quickRecursive - Function that sorts a partition of an array.
 *
 * @array: The array of integers.
 * @low: Low index of the partition.
 * @high: High index of the partition.
 * @size: Size of the array.
 */

void quickRecursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pvt = lomutoPartition(array, low, high, size);

		quickRecursive(array, low, pvt - 1, size);

		quickRecursive(array, pvt + 1, high, size);
	}
}


/**
 * quick_sort - Function that sorts an array of integers in
 * ascending order using the Quick sort algorithm.
 *
 * @array: The array of integers.
 * @size: Size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	int low = 0;
	int high = size - 1;

	quickRecursive(array, low, high, size);
}

