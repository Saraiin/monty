#include <stdio.h>
/**
 * freeTokens - Frees the global op_toks array of strings.
 */
void freeTokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}
/**
 * token_arr_len - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}
/**
 * is_delim - checks if delimitor char
 * @ch: character 
 * @delims: array of delimitors
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}
