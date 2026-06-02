#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head pointer of the stack
 * @line_number: line counter
 * @file: pointer to monty file
 * Return: 0 on success, or exits on failure
 */
int execute(char *content, stack_t **stack,
	unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", set_stack},
		{"queue", set_queue},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t\r");
	if (op == NULL || op[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t\r");

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
