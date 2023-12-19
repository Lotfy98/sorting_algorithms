#include "sort.h"
/**
 * swapInts - Swap 2 ints in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swapInts(int *a, int *b)
{
	int tmp = *a;

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
				swapInts(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swapInts(array + above, pivot);
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
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swapNodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	if (n2->next != NULL)
		n2->next->prev = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;

	(*n1)->next = n2->next;
	(*n1)->prev = n2;

	n2->prev = (*n1)->prev;
	n2->next = *n1;

	*n1 = n2->prev;
}
