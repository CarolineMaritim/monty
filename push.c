#include "monty.h"


/**
 * _push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;
	int i;

	current = malloc(sizeof(stack_t));
	if (current == NULL)
	{
		_op_tokError(_mallocError());
		return;
	}

	if (op_toks[1] == NULL)
	{
		_op_tokError(_noIntError(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			_op_tokError(_noIntError(line_number));
			return;
		}
	}
	current->n = atoi(op_toks[1]);

	if (_check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		temp = (*stack)->next;
		current->prev = *stack;
		current->next = temp;
		if (temp)
			temp->prev = current;
		(*stack)->next = current;
	}
	else 
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		current->prev = temp;
		current->next = NULL;
		temp->next = current;
	}
}

