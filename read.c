#include "shell.h"
/**
 * main - our main function
 * Return:0m - 1
 */

int main(void)
{
	char* RA_path1 = RA_getenv("PATH");
	pid_t RA_PID;
	char *order = NULL;
	char *arg[max];
	int ko, ans, fr;
	char *t, *hash;
	int RA = 2;
	size_t size = 0;
	ssize_t ret;
	
	while (RA == 2)
	{
		amnaandruba_print("RA_shell$ ");
		ret = getline(&order, &size, stdin);
		if (ret == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		hash = RA_strchr(order, '#');
		if (hash != NULL)
		{
			*hash = '\0';
		}
		ans = RA_strcspn(order, "\n");
		order[ans] = '\0';
		t = strtok(order, " ");
		for (ko = 0; t != NULL && ko < max - 1; ko++)
		{
			arg[ko] = malloc(RA_strlen(order) + 1);
			RA_strcpy(arg[ko], t);
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
			RA_buffer(order, RA_path1, arg);


		amnaandruba_print("command not found\n");
		exit(EXIT_SUCCESS);
		}
		else
		{
			int RA_status;

			waitpid(RA_PID, &RA_status, 0);
		}
		for (fr = 0; fr < ko; fr++)
		{
			free(arg[fr]);
		}}
		return (0);
}
/**
 * RA_buffer - function
 */
void RA_buffer(char *s, char *path, char **arg)
{
	char* token = strtok(path,":");

	while (token != NULL)
	{
		char abs_path[MAX_PATH];

		RA_strcpy(abs_path, token);
		RA_strcat(abs_path, "/");
		RA_strcat(abs_path, s);
		
		if (access(abs_path, X_OK) != -1)
		{
			execve(abs_path, arg, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		 token = strtok(NULL, ":");
	}
}




