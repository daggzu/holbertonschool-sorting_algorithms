#include "sort.h"

/**
 * _swap - Swap two numbers.
 * @a: Integer
 * @b: Integer
 **/

void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}

/**
 * _split - Split the array and takes the last element as pivot
 * @arr: Array
 * @min: First element
 * @last: Last element
 * @size: Size
 * Return: Integer
 **/
int _split(int *arr, int min, int last, size_t size)
{
	int piv;
	int i = (min);
	int j;

	piv = arr[last];
	for (j = min; j < last; j++)
	{
		if (arr[j] <= piv)
		{

			_swap(&arr[i], &arr[j]);


			if (i != j)
				print_array(arr, size);

			i++;

		}
	}

	_swap(&arr[i], &arr[last]);
	if (i != j)
		print_array(arr, size);

	return (i);
}

/**
 * quick_sort_array - The quick short array
 * @arr: arr
 * @min: min
 * @last: last
 * @size: size
 * Return: Nothing
 */
void quick_sort_array(int *arr, int min, int last, size_t size)
{

	int piv;

	if (min < last)
	{
		piv = _split(arr, min, last, size);
		quick_sort_array(arr, min, (piv - 1), size);
		quick_sort_array(arr, (piv + 1), last, size);
	}
}

/**
 * quick_sort -Sort an array using quick_sort algorithm
 * @array: array
 * @size: size
 **/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_array(array, 0, size - 1, size);
}
