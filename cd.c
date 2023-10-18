#include "shell.h"
/**
 * RA_cd - this is a function.
 * @com: parameter.
 */
void RA_cd(char **com)
{
if (!com[1] || RA_strcmp(com[1], "-") == 0)
{
chdir(RA_getenv("HOME"));
}
else
{
if ((chdir(com[1]) != 0))
{
free(com);
perror("cd");
}
}
}
