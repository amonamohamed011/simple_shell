#include "shell.h"
void proceed_order(const char *order)
{
pid_t child_pid = fork();
if (child_pid == -1)
{
perror("fork error");
return 1;
}
else if (child_pid == 0)
{
printf("this is child process (PID : %d)\n", getpid());
execlp(order, order, (char *)NULL);
perror(execlp);
return 1;
}
else
{
printf("this is child process (PID : %d)\n", getpid());
wait(NULL);
}
}
