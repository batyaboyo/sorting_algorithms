#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: Contain the elements
 * @size: Is the size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t count = 0;
	int aux = 0, i = 0;

	if (array == NULL)
		return;
	while (i == 0)
	{
		i = 1;
		for (count = 0; count < size - 1; count++)
		{
			if (array[count] > array[count + 1])
			{
				aux = array[count + 1];
				array[count + 1] = array[count];
				array[count] = aux;
				i = 0;
				print_array(array, size);
			}
		}
	}
}
