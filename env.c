#include "shell.h"
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
