#include "monty.h"

/**
 * _pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
}

/**
 * _pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		_op_tokError(_pintError(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * _pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	if ((*stack)->next == NULL)
	{
		_op_tokError(_popError(line_number));
		return;
	}

	new = (*stack)->next->next;
	free((*stack)->next);
	if (new)
		new->prev = *stack;
	(*stack)->next = new;
}
