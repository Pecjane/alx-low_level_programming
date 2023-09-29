#include "main.h"
/**
 * set_bit - set bit to 1
 * @n: pointer number
 * @index: index number
 * Return: num
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
