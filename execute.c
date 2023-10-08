#include "shell.h"
/**
 *  proceed_order -  function that excute the code
 *  order:the command
 *  Return:0 - 1
 */
void proceed_order(const char *order)
{
	pid_t c_pid = fork();

	if (c_pid == 0)
	{
		execlp(order, order, (char *)NULL);

		perror("execlp");
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
