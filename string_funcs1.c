#include "monty.h"

/**
 * _isDelim - checks if stream has delimitor char
 *
 * @ch: character in stream
 *
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */

int _isDelim(char ch, char *delims)
{
	int idx = 0;

	while (delims[idx])
	{
		if (delims[idx] == ch)
			return (1);
		idx++;
	}
	return (0);
}

/**
 * _word_len - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use to delimit words
 *
 * Return: word length of current word
 */

int _word_len(char *str, char *delims)
{
	int wlength = 0, pending = 1, idx = 0;

	while (*(str + idx))
	{
		if (_isDelim(str[idx], delims))
			pending = 1;
		else if (pending)
		{
			wlength++;
		}
		if (wlength > 0 && _isDelim(str[idx], delims))
			break;
		idx++;
	}
	return (wlength);
}

/**
 * _word_count - gets the word count of a string
 *
 * @str: string to get word count from
 * @delims: delimitors to use to delimit words
 *
 * Return: the word count of the string
 */

int _word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, idx = 0;

	while (*(str + idx))
	{
		if (_isDelim(str[idx], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		idx++;
	}
	return (wc);
}

/**
 * _word_next - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 */

char *_word_next(char *str, char *delims)
{
	int pending = 0;
	int idx = 0;

	while (*(str + idx))
	{
		if (_isDelim(str[idx], delims))
			pending = 1;
		else if (pending)
			break;
		idx++;
	}
	return (str + idx);
}

