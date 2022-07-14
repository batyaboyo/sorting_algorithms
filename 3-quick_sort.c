#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
  * swap - swap two elements
  * @a: element a
  * @b: element b
  */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
  *partition - Lomuto partition scheme
  * @array: array of integers
  * @low: lowest index
  * @high: last index
  * @size: number of integer
  * Return: pivot index
  */
int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quickSort - quicksort in Lomuto partition scheme
 * @array: array of integers
 * @low: lowest index
 * @high: last index
 * @size: number of integers
 * Return: void
 */
void quickSort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quickSort(array, low, pi - 1, size);
		quickSort(array, pi + 1, high, size);
	}

}
/**
  * quick_sort - call quickSort function
  * @array: array of integers
  * @size: number of integers
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);

}
