#include "shell.h"
/**
 * main - our main function
 * Return:0m - 1
 */

int main() {
	char* RA_path1 = RA_getenv("PATH");
	pid_t RA_PID;
	char order [max];
	char *arg[max];
	int ko;
	char *t;
	int RA = 2;
	int ans;
	
	while (RA == 2)
	{
		amnaandruba_print("RA_shell$ ");
		fgets(order, sizeof(order), stdin);
		ans = RA_strcspn(order, "\n");
		order[ans] = '\0';
		t = strtok(order, " ");
		for (ko = 0; t != NULL && ko < max - 1; ko++)
		{
			arg[ko] = t;
			t =strtok(NULL, " ");
		}
		arg[ko] = NULL;

		if (RA_strcmp(arg[0], "cd") == 0)
		{
			RA_cd(arg);
			continue;
		}
	       	if (RA_strcmp(order, "exit") == 0)
		{
			break;
		}
		if (RA_strcmp(order, "env") == 0)
		{ 
			RA_env();
			continue;
		}
	
		RA_PID = fork();
		if (RA_PID < 0) 
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} 
		else if (RA_PID == 0) 
		{
			char* token = strtok(RA_path1,":");
			while (token != NULL) 
			{
				char abs_path[MAX_PATH];
				RA_strcpy(abs_path, token);
				RA_strcat(abs_path, "/");
				RA_strcat(abs_path, order);
				if (access(abs_path, X_OK) != -1) 
				{
					execve(abs_path, arg, NULL);
					perror("execve");
					exit(EXIT_FAILURE);
				}

				token = strtok(NULL, ":");
			}

		amnaandruba_print("command not found\n");
		exit(EXIT_SUCCESS);
		} 
		else 
		{
			int RA_status;
			waitpid(RA_PID, &RA_status, 0);
		}
		}
		return (0);

}

