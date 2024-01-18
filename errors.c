#include "monty.h"

/**
 * errfunction - Display appropriate error messages based on the error code.
 * @error_code: The error code indicating the type of error.
 * @...: Additional arguments depending on the error code.
 *
 * Error Codes:
 * - (1) => No file or more than one file provided to the program.
 * - (2) => Unable to open or read the specified file.
 * - (3) => Invalid instruction in the file.
 * - (4) => Memory allocation failure (malloc).
 * - (5) => Invalid parameter for the "push" instruction (not an integer).
 */
void errfunction(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_errors - Handle additional errors during execution.
 * @error_code: The error code indicating the type of error.
 * @...: Additional arguments depending on the error code.
 *
 * Error Codes:
 * - (6) => Attempted "pint" on an empty stack.
 * - (7) => Attempted "pop" on an empty stack.
 * - (8) => Stack is too short for the operation.
 * - (9) => Division by zero.
 */
void more_errors(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
	fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - Handle string-related errors during execution.
 * @error_code: The error code indicating the type of error.
 * @...: Additional arguments depending on the error code.
 *
 * Error Codes:
 * - (10) => Value inside a node is outside ASCII bounds.
 * - (11) => Attempted "pchar" on an empty stack.
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
	fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
