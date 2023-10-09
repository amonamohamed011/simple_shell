#include "shell.h"
/**
 * amnaandruba_print - function
 * @letter:the string to be printed
 * Return:This function doesnot return any value
 */
void amnaandruba_print(const char *letter)
{
	write(1, letter, strlen(letter));
}
