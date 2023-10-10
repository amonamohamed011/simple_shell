#include "shell.h"
/**
 *  proceed_order -  function that excute the code
 *  order:the command
 *  Return:0 - 1
 */
void proceed_order(const char *order)
{
	pid_t c_pid = fork();
	int num;
	char *com[200];
	char *RA_tok;

	if (c_pid == 0)
	{
		for (num = 0 , RA_tok = strtok((char *)order, " "); RA_tok != NULL; RA_tok = strtok(NULL, " "))
		{	com[num] = RA_tok;
			num++;
		}
		com[num] = NULL;
		execvp(com[0], com);
		amnaandruba_print("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (c_pid == -1)
	{
		perror("Error");
		 exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
