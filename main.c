#include "shell.h"
int main(void)
{
char order[100];
while (1)
{
show_prompt();
learn_order(order, sizeof(order));
precced_order(order);
}
return 0;
}
