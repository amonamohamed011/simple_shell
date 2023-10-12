#ifndef SHELL_H
#define SHELL_H

#define max 256
extern char **environ;
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void amnaandruba_print(char *letter);
void proceed_order(char *order);
void show_prompt(void);
void learn_order(char *order, size_t s);
void RA_env();
int RA_strcmp(char *s1, char *s2);
char *RA_strcpy(char *s1, char *s2);
char *RA_strcat(char *s1, char *s2);
#endif
