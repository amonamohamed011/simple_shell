#include "shell.h"
/**
 * main - our main function
 * Return:0m - 1
 */

int main(void)
{
	char *arg[max];
	int ko, ans, fret, rp;
	char *t, *order;
	
	while (10 > 8)
	{
		order = RA_get();	
		if(order == NULL)
		{	exit(EXIT_FAILURE); }
		RA_hash(order);
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
		fret = RA_func(arg, order);
		if(fret == 2)
		{	continue; }
		else if(fret == -1)
		{	break; }
		rp = RA_proc(arg, order);
		if(rp == -1)
		{	exit(EXIT_FAILURE); }
		else if(rp == 1)
		{	exit(EXIT_SUCCESS); }
		RA_free(arg, order);
	}
		return (0);
}
/**
 * RA_buffer - function
 */
void RA_buffer(char *s, char *path, char **arg)
{
	char* token = strtok(path,":");
	char* p;

	while (token != NULL)
	{
		char abs_path[MAX_PATH];
		p = RA_strchr(s, '/');
		if(p == NULL)
		{
			RA_strcpy(abs_path, token);
			RA_strcat(abs_path, "/");
			RA_strcat(abs_path, s);
		}
		else
		{
			RA_strcpy(abs_path, s);
		}
		
		if (access(abs_path, X_OK) != -1)
		{
			execve(abs_path, arg, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		 token = strtok(NULL, ":");
	}
}
/**
 * RA_get - function
 */
char *RA_get(void)
{
	 char *order = NULL;
	 size_t size = 0;
	 ssize_t ret;

	amnaandruba_print("RA_shell$ ");
	ret = getline(&order, &size, stdin);
	if (ret == -1)
	{
		perror("getline");
		free(order);
		return(NULL);
	}
	return (order);
}
/**
 * RA_hash - function
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
/**
 * RA_free - function
 */
void RA_free(char **arg, char *order)
{
	free(order);
	free(*arg);
}
/**
 * RA_proc - function
 */
int RA_proc(char **arg, char *order)
{
	char* RA_path1 = RA_getenv("PATH");
	pid_t RA_PID;
	int RA_status;

	RA_PID = fork();
	if (RA_PID < 0)
	{
		perror("fork");
		RA_free(arg, order);
		return (-1);
	}
	else if (RA_PID == 0)
	{
		RA_buffer(order, RA_path1, arg);
		amnaandruba_print("command not found\n");
		RA_free(arg, order);
		return (1);
	}
	else
		  { waitpid(RA_PID, &RA_status, 0); }
	return (0);
}


														                



	
	
		





