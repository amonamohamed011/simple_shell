#include "shell.h"
/**
 * main - our main function
 * Return:0m - 1
 */
int main(void)
{
	char **arg;
	int fret;
	char *order;
	int RA_status = 0;

	while (10 > 8)
	{
		order = RA_get();
		if (order == NULL)
		{
			if (isatty(STDIN_FILENO))
				amnaandruba_print("\n");
			return (RA_status);
		}
		RA_hash(order);
		order[RA_strcspn(order, "\n")] = '\0';
		if (RA_empty(order))
		{
			free(order);
			continue;
		}
		arg = RA_token(order);
		if (!arg)
		{
			free(arg);
			continue;
		}
		fret = RA_func(arg, order);
		if (fret == 2)
		{	continue; }
		else if (fret == -1)
		{	break; }
		RA_status = RA_proc(arg, order);
		RA_free(arg, order);
	}
		return (RA_status);
}
/**
 * RA_buffer - function
 * @order:fisrt parameter
 * @path:second parameter
 * @arg:third parameter
 * Return:int
 */
int RA_buffer(char *path, char **arg, char *order)
{
	char *token = strtok(path, ":");
	char *p;

	while (token != NULL)
	{
		char abs_path[MAX_PATH];

		p = RA_strchr(arg[0], '/');
		if (p == NULL)
		{
			RA_strcpy(abs_path, token);
			RA_strcat(abs_path, "/");
			RA_strcat(abs_path, arg[0]);
		}
		else
		{
			RA_strcpy(abs_path, arg[0]);
		}
		if (abs_path == NULL)
		{
			free(arg);
			perror(arg[0]);
			return (127);
		}
		if (access(abs_path, X_OK) != -1)
		{
			execve(abs_path, arg, environ);
			free(arg);
			free(order);
			exit(127);
		}
		 token = strtok(NULL, ":");
	}
	return (0);
}
/**
 * RA_get - function
 * Return:char
 */
char *RA_get(void)
{
	 char *order = NULL;
	 size_t size = 0;
	 ssize_t ret;
	 char *order2 = NULL;

	if (isatty(STDIN_FILENO))
	{	amnaandruba_print("$ "); }
	ret = getline(&order, &size, stdin);
	if (ret == -1)
	{
		free(order);
		return (NULL);
	}
	order2 = malloc(ret + 1);
	RA_strncpy(order2, order, ret);
	order2[ret] = '\0';
	free(order);
	return (order2);
}
/**
 * RA_free - function
 * @arg:first parameter
 * @order:second parameter
 */
void RA_free(char **arg, char *order)
{
	free(order);
	free(arg);
}
/**
 * RA_proc - function
 * @arg:first parameter
 * @order:second parameter
 * Return:num
*/
int RA_proc(char **arg, char *order)
{
	char *RA_path1 = RA_getenv("PATH");
	pid_t RA_PID;
	int RA_status;

	RA_PID = fork();
	if (RA_PID == 0)
	{
		RA_status = RA_buffer(RA_path1, arg, order);
		amnaandruba_print("command not found\n");
		RA_free(arg, order);
		return (RA_status);
	}
	else
		  { waitpid(RA_PID, &RA_status, 0); }
	return (WEXITSTATUS(RA_status));
}
