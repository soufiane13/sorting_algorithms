#include "sort.h"

/**
 * get_max_c - Get the max_cimum value in an array of integers.
 * @array: An array .
 * @size: The size of the array.
 *
 * Return: The max_cimum integer in the array.
 */
int get_max_c(int *array, int size)
{
	int max_c, i;

	for (max_c = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_c)
			max_c = array[i];
	}

	return (max_c);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array .
 * @size: The size of the array.
 *
 * Description: Prints the counting array .
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted_c, max_c, i;

	if (array == NULL || size < 2)
		return;

	sorted_c = malloc(sizeof(int) * size);
	if (sorted_c == NULL)
		return;
	max_c = get_max_c(array, size);
	count = malloc(sizeof(int) * (max_c + 1));
	if (count == NULL)
	{
		free(sorted_c);
		return;
	}

	for (i = 0; i < (max_c + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max_c + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max_c + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_c[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_c[i];

	free(sorted_c);
	free(count);
}
