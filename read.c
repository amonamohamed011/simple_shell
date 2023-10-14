#include "shell.h"
/**
 * main - our main function
 * Return:0m - 1
 */

int main() {
	char* path = getenv("PATH");
	pid_t PID;
	char order [max];
	char *arg[max];
	int ko;
	char *t;
	
	while (1) 
	{
		amnaandruba_print("shell$ ");
		fgets(order, sizeof(order), stdin);
		order[strcspn(order, "\n")] = '\0';
		t = strtok(order, " ");
		for (ko = 0; t != NULL && ko < max - 1; ko++)
		{
			arg[ko] = t;
			t = strtok(NULL, " ");
		}
		arg[ko] = NULL;

						          
	       	if (strcmp(order, "exit") == 0)
		{
			break;
		}
		if (strcmp(order, "env") == 0)
		{ 
			RA_env();
			continue;
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
				strcpy(abs_path, token);
				strcat(abs_path, "/");
				strcat(abs_path, order);
				if (access(abs_path, X_OK) != -1) 
				{
					execve(abs_path, arg, NULL);
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

char * const * addNullTerminator(char *arg) {
	int l = strlen(arg);
	char **result = malloc((l + 1) * sizeof(char *));
	 char *nullTerminator = malloc(2 * sizeof(char));

	if (result == NULL) {
		amnaandruba_print( "Memory allocation failed\n");
		exit(1);
	}
	result[0] = arg;
	if (nullTerminator == NULL) 
	{
		amnaandruba_print("Memory allocation failed\n");
		exit(1);
	}
	*nullTerminator = '\0';
	result[1] = nullTerminator;
	return (char * const *)result;
}
