#include "shell.h"
/**
 *  proceed_order -  function that excute the code
 *  order:the command
 *  Return:0 - 1
 */
void proceed_order(char *order)
{
	pid_t c_pid;
	char *RA_path = getenv("PATH");
	char *ptoken;
	char *u_path[max];
	

	c_pid = fork();
	if (c_pid == 0)
	{
		for (ptoken = strtok(RA_path,":");ptoken != NULL;)
		{
			strcpy(*u_path, ptoken);
			strcat(*u_path, "/");
			strcat(*u_path, order);
			if (access(*u_path, X_OK) != -1)
			{
				strcat(*u_path,"\0");
				execve(u_path[0],u_path, environ);
				perror("execeve");
				exit(EXIT_FAILURE);
			}
			ptoken = RA_strtok(NULL, ":");
		}
		

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
