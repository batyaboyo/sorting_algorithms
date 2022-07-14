#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
  * selection_sort - sorts an array of int in ascending order
  * using the Selection sort algorithm
  * @array: array to sort
  * @size: size of an array
  */
void selection_sort(int *array, size_t size)
{
	size_t x, y, temp, min;

	if (array == NULL)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min])
				min = y;
		}
		if (min != x)
		{
			temp = array[min];
			array[min] = array[x];
			array[x] = temp;
			print_array(array, size);
		}
	}
}
