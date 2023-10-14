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
/**
 * RA_getenv - our custom function
 * @RA_name:the parameter
 * Return:depends
 */
char *RA_getenv(const char *name) {
	char *RA_var;
	int len = strlen(name);
	char **AR_env;

	for (AR_env = environ; *AR_env != NULL; AR_env++) {
		RA_var = *AR_env;
		if (strncmp(name, RA_var, len) == 0 && RA_var[len] == '=')
	       	{
			 return &RA_var[len + 1];
		}
	}

	return (NULL);
}

