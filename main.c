#include "monty.h"

/* Define the global variable bus */
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * _getline - portable implementation of POSIX getline for systems without it
 * @lineptr: pointer to buffer containing read text
 * @n: size of buffer
 * @stream: stream to read from
 * Return: number of characters read, or -1 on EOF or failure
 */
long _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;
	size_t new_size;
	char *new_ptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if (pos + 1 >= *n)
		{
			new_size = *n * 2;
			new_ptr = realloc(*lineptr, new_size);
			if (new_ptr == NULL)
				return (-1);
			*lineptr = new_ptr;
			*n = new_size;
		}

		(*lineptr)[pos++] = c;
		if (c == '\n')
			break;
	}

	if (pos == 0)
		return (-1);

	(*lineptr)[pos] = '\0';
	return ((long)pos);
}

/**
 * main - entry point for the Monty interpreter
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	size_t size = 0;
	char *content = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	long read_bytes;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read_bytes = _getline(&content, &size, file)) > 0)
	{
		line_number++;
		bus.content = content;
		execute(content, &stack, line_number, file);
	}

	free(content);
	free_stack(stack);
	fclose(file);
	return (0);
}
