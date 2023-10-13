#ifndef SHELL_H
#define SHELL_H

#define max 256
extern char **environ;
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#define MAX_order 100
#define MAX_PATH 256
void amnaandruba_print(char *letter);
void RA_env();
int RA_strcmp(char *s1, char *s2);
char *RA_strcpy(char *s1, char *s2);
char *RA_strcat(char *s1, char *s2);
int input(void);
char * const *addNullTerminator(char *arg);
#endif
