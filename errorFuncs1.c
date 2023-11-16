#include "monty.h"

/**
 * _op_tokError - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void _op_tokError(int error_code)
{
	int toks_len = 0, idx = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		_mallocError();
		return;
	}
	while (idx < toks_len)
	{
		new_toks[idx] = op_toks[idx];
		idx++;
	}
	exit_str = _getInt(error_code);
	if (!exit_str)
	{
		free(new_toks);
		_mallocError();
		return;
	}
	new_toks[idx++] = exit_str;
	new_toks[idx] = NULL;
	free(op_toks);
	op_toks = new_toks;
}

