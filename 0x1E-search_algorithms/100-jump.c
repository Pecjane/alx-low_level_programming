#include "search_algos.h"
/**
 * jump_search - Searches for a value in a sorted array
 *               of integers using jump search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the first index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 *              Uses the square root of the array size as the jump step.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, High, jump;

	if (array == NULL || size == 0)
		return (-1);

	jump = sqrt(size);
	for (i = High = 0; High < size && array[High] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", High, array[High]);
		i = High;
		High += jump;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, High);

	High = High < size - 1 ? High : size - 1;
	for (; i < High && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
