#include "sort.h"
#include <stddef.h>

/**
 * swapNumbers - Swap 2 integers in array
 * @firstInt: First integer
 * @secondInt: Second integer
 */
void swapNumbers(int *firstInt, int *secondInt)
{
	int tmp;

	tmp = *firstInt;
	*firstInt = *secondInt;
	*secondInt = tmp;
}

/**
 * bubble_sort - Function sorts array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: Prints the array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t length = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < length  - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swapNumbers(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
