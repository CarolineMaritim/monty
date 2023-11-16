#include "monty.h"
/**
 * _freeStack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void _freeStack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * _freeTokens - Frees the global op_toks array of strings.
 */
void _freeTokens(void)
{
	size_t idx = 0;

	if (op_toks == NULL)
		return;

	for (idx = 0; op_toks[idx]; idx++)
		free(op_toks[idx]);

	free(op_toks);
}

