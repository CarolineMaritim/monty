#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

/*MACROS*/
#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _freeStack(stack_t **stack);
int_init_stack(stack_t **stack);
int _check_mode(stack_t *stack);
void _freeTokens(void);
unsigned int token_arr_len(void);
int _init_monty(FILE *script_fd);
void _op_tokError(int error_code);


void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

char **_str_tok(char *str, char *delims);
char *_getInt(int n);
unsigned int _abs(int);
int _numbase_len(unsigned int n, unsigned int base);
void _numbase_buff(unsigned int n, unsigned int base,
		char *buff, int buff_size);

int _usageError(void);
int _mallocError(void);
int _fileOpenError(char *filename);
int _unknownOpError(char *opcode, unsigned int line_number);
int _noIntError(unsigned int line_number);
int _popError(unsigned int line_number);
int _pintError(unsigned int line_number);

int _isDelim(char ch, char *delims);
int _word_len(char *str, char *delims);
int _word_count(char *str, char *delims);
char *_word_next(char *str, char *delims);


	int _checkline(char *line, char *delims)
void (*_getopcode(char *opcode))(stack_t**, unsigned int)

#endif

