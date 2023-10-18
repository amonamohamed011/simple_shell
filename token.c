#include "shell.h"
/**
 * RA_token - function
 * @order:parameter
 * Return:int
 */
char **RA_token(char *order)
{
	int k = 0;
	char *t;
	char **arg;

	arg = malloc(sizeof(char *) * 15);
	if (!arg)
	{
		return (NULL);
	}
	t = strtok(order, " \t");
	while (t != NULL && (*t == ' ' || *t == '\t'))
	{
		/*arg[k] = malloc(RA_strlen(order) + 1);*/
		/*RA_strcpy(arg[k], t);*/
		t = strtok(NULL, " \t\n");
		}
	while (t != NULL)
	{
		arg[k] = t;
		t = strtok(NULL, " \t\n");
		k++;
	}

	arg[k] = NULL;
	free(t);
	return (arg);
}
/**
 * RA_func - function
 * @farg:first parameter
 * @forder:para
 * Return:num
 */
int RA_func(char **farg, char *forder)
{
	if (RA_strcmp(farg[0], "cd") == 0)
	{
		RA_cd(farg);
		RA_free(farg, forder);
		return (2);
	}
	if (RA_strcmp(farg[0], "env") == 0)
	{
		RA_env();
		RA_free(farg, forder);
		return (2);
	}
	if (RA_strcmp(farg[0], "exit") == 0)
	{
		RA_free(farg, forder);
		return (-1);
	}
	return (0);
}
/**
 * RA_hash - function
 * @ohash:parameter
 */
void RA_hash(char *ohash)
{
	char *l;

	l = RA_strchr(ohash, '#');
	if (l != NULL)
	{
		*l = '\0';
	}
}
