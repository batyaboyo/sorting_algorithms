#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: Array of elements
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t count = 0, aux = 0, i = 0;
	int tmp = 0;

	if (array == NULL)
		return;
	for (count = 0; count < (size - 1); count++)
	{
		aux = count;
		for (i = count + 1; i < size; i++)
		{
			if (array[i] < array[aux])
			{
				aux = i;

			}
		}
		if (array[aux] != array[count])
		{
			tmp = array[aux];
			array[aux] = array[count];
			array[count] = tmp;
			print_array(array, size);
		}
	}
}
