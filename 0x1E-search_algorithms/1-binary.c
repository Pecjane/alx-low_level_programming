#include "search_algos.h"
/**
 * binary_search - Searches for a value in a sorted array
 *                 of integers using binary search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t H, L, i, j, mid;

	if (array == NULL || size == 0)
		return (-1);
	H = size - 1;
	L = 0;

	while (L <= H)
	{
		i = L;
		j = H;
		printf("Searching in array: ");
		for (; i <= j; i++)
		{
			printf("%d", array[i]);
			if (i != j)
				printf(", ");
		}
		printf("\n");
		mid = (L + H) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
			H = mid - 1;
		else
			L = mid + 1;
	}
	return (-1);
}
