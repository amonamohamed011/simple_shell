#include "shell.h"
/**
 * learn_order - function that do the commands
 * @order:char
 * @s:the length
 */
void learn_order(char *order, size_t s)
{
	int lea = 8;
	int str;

	if (lea == 8)
	{
		if (fgets(order, s, stdin) == NULL)
		{
			str = strcspn(order, "\n");
			order[str] = '\0';
			if (RA_strcmp(order, "env") == 0)
			{
				printf("match");
				RA_env();
			}
			if (RA_strcmp(order, "exit") == 0)
			{
				return;
			}
			else if(feof(stdin))
			{
				amnaandruba_print("\n");
				exit(EXIT_SUCCESS);
			}
			else
			{
				amnaandruba_print("Error while reading input.\n");
				exit(EXIT_FAILURE);
			}
		}
		str = strcspn(order, "\n");
		order[str] = '\0';
	}
}
/**
 * RA_env - env custom function
 */
void RA_env()
{
	char **env = environ;
	while (*env)
	{
		amnaandruba_print(*env);
		amnaandruba_print("\n");
		env++;
	}
}
