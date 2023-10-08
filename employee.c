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
			if(feof(stdin))
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
