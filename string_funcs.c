#include "monty.h"

/**
 * _abs - gets the absolute value of an integer
 * @i: integer to get absolute value of
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int idx)
{
	if (idx < 0)
		return (-(unsigned int)idx);
	return ((unsigned int)idx);
}

/**
 * _numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int _numbase_len(unsigned int n, unsigned int base)
{
	int length = 1;

	while (n > base - 1)
	{
		length++;
		n /= base;
	}
	return (length);
}

/**
 * _numbase_buff - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void _numbase_buff(unsigned int n, unsigned int base,
		char *buff, int buff_size)
{
	int rem, idx = buff_size - 1;

	buff[buff_size] = '\0';
	while (idx >= 0)
	{
		rem = n % base;
		if (rem > 9)
			buff[idx] = rem + 87;
		else
			buff[idx] = rem + '0';
		n /= base;
		idx--;
	}
}

/**
 * _getInt - gets a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *_getInt(int n)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(n);
	length = _numbase_len(temp, 10);

	if (n < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	_numbase_buff(temp, 10, ret, length);
	if (n < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}
