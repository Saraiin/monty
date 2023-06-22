#include "monty.h"
/**
 * popError - Prints pop error messages for empty stacks.
 * @line_number: Line number in script where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int popError(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * pintError - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pintError(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * divError - Prints division error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int divError(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * pcharError - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pcharError(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

