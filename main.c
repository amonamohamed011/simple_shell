#include "shell.h"
/**
 * main - our entry point to the shell
 * Return:alwaaays zero
 */
int main(void)
{
	char order[100];

	while (1)
	{
		show_prompt();
		learn_order(order, sizeof(order));
		proceed_order(order);
	

	}
	return(0);
}
