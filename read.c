#include "shell.h"
/**
 * main - our main function
 * Return:0m - 1
 */

int main() {
	char* path = getenv("PATH");
	pid_t PID;
	char * const *n;
	char order [max];
	
	while (1) 
	{
		amnaandruba_print("shell$ ");
		fgets(order, sizeof(order), stdin);
		order[strcspn(order, "\n")] = '\0';

						          
	       	if (RA_strcmp(order, "exit") == 0)
		{
			break;
		}
		if (RA_strcmp(order, "env") == 0)
		{ 
			RA_env();
		}
	
		PID = fork();
		if (PID < 0) 
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} 
		else if (PID == 0) 
		{
			char* token = strtok(path, ":");
			while (token != NULL) 
			{
				char abs_path[MAX_PATH];
				RA_strcpy(abs_path, token);
				RA_strcat(abs_path, "/");
				RA_strcat(abs_path, order);
				if (access(abs_path, X_OK) != -1) 
				{
					n = addNullTerminator(abs_path);
					execve(abs_path, n, environ);
					perror("execve");
					exit(EXIT_FAILURE);
				}

				token = strtok(NULL, ":");
			}

		amnaandruba_print("order not found\n");
		exit(EXIT_SUCCESS);
		} 
		else 
		{
			int status;
			waitpid(PID, &status, 0);
		}
		}
		return (0);

}

char *const *addNullTerminator(char *arg) 
{
	int s = 0;
	char * const *result = NULL;

	while(arg[s] != NULL)
	{
		s++;
	}
	result = malloc(size of char * 

	result[s] = NULL;
	return (result);
	}
