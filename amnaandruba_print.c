#include "shell.h"
/**
 * amnaandruba_print - this is a function.
 * @letter:the string to be printed.
 * Return:This function does not return any value.
 */
void amnaandruba_print(char *letter)
{
write(1, letter, strlen(letter));
}
