#include "sort.h"
/**
 * swap - Swap elements
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
	int tmp = 0;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Partition array
 * @array: Array of elements
 * @size: Size of the array
 * @start: Start the comparision
 * @pivot: Pivot
 * Return: Return the pivot element
 */
int partition(int *array, size_t size, size_t start, size_t pivot)
{
	size_t count;

	for (count = start; count < pivot; count++)
	{
		if (array[count] < array[pivot])
		{
			if (count != start)
			{
				swap(&array[start], &array[count]);
				print_array(array, size);
			}
			start++;
		}
	}
	if (array[start] > array[pivot])
	{
		swap(&array[start], &array[pivot]);
		pivot = start;
		print_array(array, size);
	}
	return (pivot);
}

/**
 * _quick - lquick
 * @array: Given array.
 * @size: Size of given array.
 * @start: Start
 * @end: End
 *
 */
void _quick(int *array, size_t size, size_t start, size_t end)
{
	size_t split;


	if (end == 0 || end <= start)
		return;

	split = partition(array, size, start, end);
	if (split != 0 && split >= start)
		_quick(array, size, start, split - 1);
	if (split < size - 1)
		_quick(array, size, split + 1, end);
}

/**
 * quick_sort - sorts an array of integers in ascending order Quick sort
 * @array: Array of elements
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_quick(array, size, 0, size - 1);
}
