#include "monty.h"
char **op_toks = NULL;
/**
 * main - the entry point for Monty Interp
 *
 * @ac: number of arguments passed to the program
 * @av: pointer to an array of char pointers to arguments
 *
 * Return: 'EXIT_SUCCESS' on success or  'EXIT_FAILURE' on error
 */
int main(int ac, char **av)
{
	int exitCode = EXIT_SUCCESS;
	FILE *fileToOpen = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fileToOpen = fopen(av[1], "r");
	if (fileToOpen == NULL)
		return (openFileError(av[1]));
	exitCode = runMonty(fileToOpen);
	fclose(fileToOpen);
	return (exitCode);
}
