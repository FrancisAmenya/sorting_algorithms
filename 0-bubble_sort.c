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
 * bubble_sort - Sort an array sorted forward(ascending).
 * @arrayInts: Int array sorted.
 * @size: The size.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *arrayInts, size_t size)
{
	size_t i, arraylen = size;
	bool bubbly = false;

	if (arrayInts == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < arraylen - 1; i++)
		{
			if (arrayInts[i] > arrayInts[i + 1])
			{
				swap_my_ints(arrayInts + i, arrayInts + i + 1);
				print_array(arrayInts, size);
				bubbly = false;
			}
		}
		arraylen--;
	}
}
