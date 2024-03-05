#include "sort.h"

/**
 * swap_my_ints - Swap two integers in an array.
 * @na: The first int to swap.
 * @nb: The second int to swap.
 */
void swap_my_ints(int *na, int *nb)
{
	int tempInt;

	tempInt = *na;
	*na = *nb;
	*nb = tempInt;
}

/**
 * selection_sort - Sort an array of integers in ascension
 *                  using the selection sort algorithm.
 * @array: An array of intes.
 * @size: The size.
 *
 * Description: Prints the array after each swap done.
 */
void selection_sort(int *array, size_t size)
{
	int *minint;
	size_t inti, intj;

	if (array == NULL || size < 2)
		return;

	for (inti = 0; inti < size - 1; inti++)
	{
		minint = array + inti;
		for (intj = inti + 1; intj < size; intj++)
			minint = (array[intj] < *minint) ? (array + intj) : minint;

		if ((array + inti) != minint)
		{
			swap_my_ints(array + inti, minint);
			print_array(array, size);
		}
	}
}
