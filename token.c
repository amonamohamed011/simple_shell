#include "shell.h"
/**
 * RA_token - function
 */
int RA_token(char *order)
{
	int a, k;
	char *t;
	char *arg[max];

	a = RA_strcspn(order, "\n");
	order[a] = '\0';
	t = strtok(order, " ");
	for(k = 0; t != NULL && k < max - 1; k++)
	{
		arg[k] = malloc(RA_strlen(order) + 1);
		RA_strcpy(arg[k], t);
		t = strtok(NULL, " ");
	}
	arg[k] = NULL;
	return(0);
	
}
/**
 * RA_func - function
 */
int RA_func(char **farg, char *forder)
{
	if(RA_strcmp(farg[0], "cd") == 0)
	{
		RA_cd(farg);
		RA_free(farg, forder);
		return (2);
	}
	if (RA_strcmp(forder, "env") == 0)
	{
		RA_env();
		free(forder);
		free(*farg);
		return (2);
	}
	if (RA_strcmp(forder, "exit") == 0)
	{
		free(forder);
		free(*farg);
		return(-1);
	}
	return(0);
}
	




