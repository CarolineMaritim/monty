#include "monty.h"

/**
 * _init_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int _init_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t length = 0, exit_stat = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);
	ssize_t res;

	if (_init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	res = getline(&line, &length, script_fd);
	while (res != -1)
	{
		line_number++;
		op_toks = _str_tok(line, DELIMS);
		if (op_toks == NULL)
		{
			if (_checkline(line, DELIMS))
				continue;
			_freeStack(&stack);
			return (_mallocError());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			_freeTokens();
			continue;
		}
		op_func = _getopcode(op_toks[0]);
		if (op_func == NULL)
		{
			_freeStack(&stack);
			exit_stat = _unknownOpError(op_toks[0], line_number);
			_freeTokens();
			break;
		}
		prev_tok_len = token_arr_len();
		op_func(&stack, line_number);
		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_stat = atoi(op_toks[prev_tok_len]);
			else
				exit_stat = EXIT_FAILURE;
			_freeTokens();
			break;
		}
		_freeTokens();
	}
	_freeStack(&stack);
	if (line && *line == 0)
	{
		free(line);
		return (_mallocError());
	}
	free(line);
	return (exit_stat);
}
