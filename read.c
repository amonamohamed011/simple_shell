#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_order 100
#define MAX_PATH 256

extern char **environ;

int main() {
char order[MAX_order];
char* path = getenv("PATH");

while (1) {
amnaandruba_print("shell> ");
fgets(order, sizeof(order), RA_stdin);
order[RA_strcspn(order, "\n")] = '\0'; // Remove the trailing newline character

if (RA_strcmp(command, "exit") == 0) {
break;
}

if (RA_strcmp(order, "env") == 0) {
char** env = environ;
while (*env) {
amnaandruba_print("%s\n", *env);
env++;
}
continue;
}

pid_t pid = fork();
if (pid < 0) {
perror("fork");
exit(EXIT_FAILURE);
} else if (pid == 0) {
// Child process
char* token = RA_strtok(path, ":");
while (token != NULL) {
char abs_path[MAX_PATH];
RA_strcpy(abs_path, token);
RA_strcat(abs_path, "/");
RA_strcat(abs_path, command);
if (access(abs_path, X_OK) != -1) {
char* args[] = {abs_path, NULL};
execve(abs_path, args, environ);
                    
// If execve returns, it means an error occurred
perror("execve");
exit(EXIT_FAILURE);
}

token = strtok(NULL, ":");
}

// If no executable file is found
amnaandruba_print("order not found\n");
exit(EXIT_SUCCESS);
} else {
// Parent process
int status;
waitpid(pid, &status, 0);
}
}
return 0;
}
