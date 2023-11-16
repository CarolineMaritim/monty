#include "monty.h"
#include <string.h>

/**
 * _checkline - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int _checkline(char *line, char *delims)
{
	int idx, j;

	for (idx = 0; line[idx]; idx++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[idx] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * _getopcode - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*_getopcode(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	int idx;

	for (idx = 0; op_funcs[idx].opcode; idx++)
	{
		if (strcmp(opcode, op_funcs[idx].opcode) == 0)
			return (op_funcs[idx].f);
	}

	return (NULL);
}
