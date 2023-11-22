#include "sort.h"

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
 * shell_sort - Sort an array of integers in ascending.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap_s, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap_s = 1; gap_s < (size / 3);)
		gap_s = gap_s * 3 + 1;

	for (; gap_s >= 1; gap_s /= 3)
	{
		for (i = gap_s; i < size; i++)
		{
			j = i;
			while (j >= gap_s && array[j - gap_s] > array[j])
			{
				swap_ints(array + j, array + (j - gap_s));
				j -= gap_s;
			}
		}
		print_array(array, size);
	}
}
