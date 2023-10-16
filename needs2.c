#include "shell.h"
/**
 * RA_strlen - counts the length
 * @s:para
 * Return:length
 */
int RA_strlen(char *s)
{
	int l;

	for (l = 0; *s != '\0'; s++)
	{	l++; }
	return (l);
}
/**
 * RA_strchr - function
 * @s:para
 * @s2:para2
 * Return:poimter
 */
char *RA_strchr(char *s, char s2)
{
	int pin;

	for (pin = 0; s[pin] != '\0'; pin++)
	{
		if (s[pin] == s2)
		{
			return (s + pin);
		}
	}
	return (NULL);
}
