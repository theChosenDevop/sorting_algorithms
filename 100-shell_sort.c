#include "sort.h"

/**
shell_sort - Sorts an array of integers in ascending order using Shell sort.
* @array: The array to be sorted.
* @size: The size of the array.
*/

void shell_sort(int *array, size_t size) {
	size_t gap = 1, i, j;
	int temp;

	/* Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0) {
		/* Perform insertion sort for elements at a specific gap */
		for (i = gap; i < size; i++) {
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		/* Print the array after each pass with the current gap */
		printf("Gap %lu: ", gap);
		for (i = 0; i < size; i++) {
			printf("%d", array[i]);
			if (i < size - 1)
				printf(", ");
		}
		printf("\n");

		/* Calculate the next gap using Knuth sequence */
		gap = (gap - 1) / 3;
	}
}
