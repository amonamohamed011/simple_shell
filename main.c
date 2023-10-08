#include "shell.h"
/**
 * main - our entry point to the shell
 * Return:alwaaays zero
 */
int main(void)
{
	int yes = 1;
	char order[100];

	while (yes == 1)
	{
		show_prompt();
		learn_order(order, sizeof(order));
		proceed_order(order);
	

	}
	return(0);
}
