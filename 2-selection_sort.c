#include "sort.h"

/**
 * swapNumbers - Swap two Numbers
 * @firstNum: First Numberto swap
 * @secondNum: Second Number to swap
 */

void swapNumbers(int *firstNum, int *secondNum)
{
	int tmp;

	tmp = *firstNum;
	*firstNum = *secondNum;
	*secondNum = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swapNumbers(array + i, min);
			print_array(array, size);
		}
	}
}
