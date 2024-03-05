#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @arrayInt: The array of integers.
 * @sizeInt: The size of the array.
 * @leftInt: The starting index of the subset to order.
 * @rightInt: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *arrayInt, size_t sizeInt, int leftInt, int rightInt)
{
	int *pivotInt, aboveInt, belowInt;

	pivotInt = arrayInt + rightInt;
	for (aboveInt = belowInt = leftInt; belowInt < rightInt; belowInt++)
	{
		if (arrayInt[belowInt] < *pivotInt)
		{
			if (aboveInt < belowInt)
			{
				swap_my_ints(arrayInt + belowInt, arrayInt + aboveInt);
				print_array(arrayInt, sizeInt);
			}
			aboveInt++;
		}
	}

	if (arrayInt[aboveInt] > *pivotInt)
	{
		swap_my_ints(arrayInt + aboveInt, pivotInt);
		print_array(arrayInt, sizeInt);
	}

	return (aboveInt);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @arrayInt: An array of integers to sort.
 * @sizeInt: The size of the array.
 * @leftInt: The starting index of the array partition to order.
 * @rightInt: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *arrayInt, size_t sizeInt, int leftInt, int rightInt)
{
	int partInt;

	if (rightInt - leftInt > 0)
	{
		partInt = lomuto_partition(arrayInt, sizeInt, leftInt, rightInt);
		lomuto_sort(arrayInt, sizeInt, leftInt, partInt - 1);
		lomuto_sort(arrayInt, sizeInt, partInt + 1, rightInt);
	}
}

/**
 * quick_sort - Sort an array of integers in ascension
 *              order using the quicksort algo.
 * @array: An array of ints.
 * @size: The array size.
 *
 * Description: Using Lomuto partition scheme. Prints
 *              the array after each swap of elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
