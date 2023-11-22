#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer .
 * @b: The second integer .
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according .
 * @array: The array .
 * @size: The size of the array.
 * @left: The starting index .
 * @right: The ending index .
 *
 * Return:  index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *p, above_l, below_l;

	p = array + right;
	for (above_l = below_l = left; below_l < right; below_l++)
	{
		if (array[below_l] < *p)
		{
			if (above_l < below_l)
			{
				swap_ints(array + below_l, array + above_l);
				print_array(array, size);
			}
			above_l++;
		}
	}

	if (array[above_l] > *p)
	{
		swap_ints(array + above_l, p);
		print_array(array, size);
	}

	return (above_l);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array .
 * @size: The size of the array.
 * @left: The starting index of the array .
 * @right: The ending index of the array .
 *
 * Description: Uses the Lomuto.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part_l;

	if (right - left > 0)
	{
		part_l = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part_l - 1);
		lomuto_sort(array, size, part_l + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending.
 * @array: An array .
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
