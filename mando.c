#include "shell.h"
/**
 * input - function that starts the shell
 * order:command
 * Return:ans
 */
int input() 
{
	int ans = 0;
	 char order[256];

	amnaandruba_print("shell$ ");
	fgets(order, sizeof(order), stdin);
	order[strcspn(order, "\n")] = '\0';

	if (strcmp(order, "exit") == 0) 
	{
		ans = -1;
	}

	if (strcmp(order, "env") == 0) 
	{
		RA_env();
		ans = 1;
	}
	return(ans);
}
