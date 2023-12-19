#include "sort.h"

void swapInts(int *a, int *b);
int lomutoPartition(int *array, size_t size, int left, int right);
void lomutoSort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swapInts - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swapInts(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomutoPartition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomutoPartition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomutoSort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomutoSort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomutoPartition(array, size, left, right);
		lomutoSort(array, size, left, part - 1);
		lomutoSort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomutoSort(array, size, 0, size - 1);
}
