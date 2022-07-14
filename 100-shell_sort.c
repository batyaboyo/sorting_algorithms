#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * shell_sort - shell sort in ascending order using Knuth sequence
 * @array: array of integers
 * @size: number of integers in array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, temp, n;

	if (array == NULL || size < 2)
		return;
	n = 1;
	while (n < size / 3)
		n = 3 * n + 1;
	while (n >= 1)
	{
		for (j = 0; j < size; j++)
		{
			for (i = 0; (i + n) < size; i++)
			{
				if (array[i] > array[i + n])
				{
					temp = array[i];
					array[i] = array[i + n];
					array[i + n] = temp;
				}
			}
		}
		print_array(array, size);
		n = (n - 1) / 3;
	}
}
