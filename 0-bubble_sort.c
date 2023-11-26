#include "sort.h"

/**
  * swap - Swap two integers in an array.
  *@a: The first integer to swap.
  *@b: The second integer to swap.
  */
void swap(int *a, int * b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
  * bubble_sort - Sort ann array of integers in ascending order.
  * @array: An array of integers to sort.
  * @size: The size of the array.
  *
  * Description: Prints the array after each swap.
  */
void bubble_sort(int *array, size_t size)
{
	int i, j, len = size;
	bool swapped;

	for (i = 0; i < len - 1; i++)
	{
		swapped = false;
		for (j = 0; j < len - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
			print_array(array, size);
			}
		}
		if (swapped == false)
			break;
	}
}
