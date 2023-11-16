#include "monty.h"
/**
 * _str_tok - takes a string and seperates its words
 *
 * @str: string to seperate into words
 * @delims: delimitors to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */

char **_str_tok(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordlength, n, idx = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = _word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (idx < wc)
	{
		wordlength = _word_len(str, delims);
		if (_isDelim(*str, delims))
		{
			str = _word_next(str, delims);
		}
		words[idx] = malloc((wordlength + 1) * sizeof(char));
		if (words[idx] == NULL)
		{
			while (idx >= 0)
			{
				idx--;
				free(words[idx]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordlength)
		{
			words[idx][n] = *(str + n);
			n++;
		}
		words[idx][n] = '\0';
		str = _word_next(str, delims);
		idx++;
	}
	words[idx] = NULL; 
	return (words);
}
#include "monty.h"
/**
 * _str_tok - takes a string and seperates its words
 *
 * @str: string to seperate into words
 * @delims: delimitors to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */

char **_str_tok(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordlength, n, idx = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = _word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (idx < wc)
	{
		wordlength = _word_len(str, delims);
		if (_isDelim(*str, delims))
		{
			str = _word_next(str, delims);
		}
		words[idx] = malloc((wordlength + 1) * sizeof(char));
		if (words[idx] == NULL)
		{
			while (idx >= 0)
			{
				idx--;
				free(words[idx]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordlength)
		{
			words[idx][n] = *(str + n);
			n++;
		}
		words[idx][n] = '\0';
		str = _word_next(str, delims);
		idx++;
	}
	words[idx] = NULL; 
	return (words);
}

