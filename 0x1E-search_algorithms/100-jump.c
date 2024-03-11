#include "search_algos.h"
/**
 * jump_search - Searches for a value in a sorted array
 * @array: the sorted array
 * @size: size of the array
 * @value: value to search
 * Return: index of the value or -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t L, H, i, j;

	L = 0;
	j = sqrt(size);
	H = j;

	while (size >= L)
	{
		if (value > array[L])
			printf("Value checked array[%ld] = [%d]\n", L, array[L]);

		if ((array[H] >= value) || (size <= H))
		{
			printf("Value found between indexes [%ld] and [%ld]\n", L, H);
			for (i = L; i <= H; i++)
			{
				printf("Value checked array[%ld] = [%d]\n", i, array[i]);
				if (array[i] == value)
					return (i);
				if (i >= size - 1)
					return (-1);
			}
			return (-1);
		}
		L = H;
		H = H + j;

	}
	return (-1);
}
