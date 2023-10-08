#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void amnaandruba_print(const char *letter);
void proceed_order(const char *order);
void show_prompt(void);
void learn_order(char *order, size_t s);
#endif
