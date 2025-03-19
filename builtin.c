#include "shell.h"
void handle(int sig){
    myexit();
}

void mypwd() {
    char buffer[PATH_MAX];
    if (getcwd(buffer, sizeof(buffer)) != NULL) {
        printf("%s\n", buffer);
    } else {
        perror("getcwd failed");
    }
}
void myexit() {
    printf("Saving session...\n");
    printf("...copying shared history...\n");
    printf("...saving history...truncating history files...\n");
    printf("...completed.\n");
    printf("[Process completed]");
    remove("/tmp/history.txt");
    exit(0);
}

void mycd(char *path) {
    if (path == NULL) {
        path = getenv("HOME Directory");
        if (path == NULL) {
            fprintf(stderr, "HOME environment variable not set\n");
            return;
        }
    }

    if (chdir(path) != 0) {
        perror("chdir failed");
    }
}
void myhelp(char* args[]) {
    if (strcmp(args[0], "pwd") == 0) {
        printf("pwd: Prints the current working directory.\n");
        printf("Usage: pwd\n");
        printf("Description: Displays the full pathname of the current directory you are in.\n");
    } else if (strcmp(args[0], "cd") == 0) {
        printf("cd: Changes the current directory.\n");
        printf("Usage: cd [path]\n");
        printf("Description: Changes the shell's current directory to the specified path. If no path is given, the command changes to the user's home directory.\n");
    } else if (strcmp(args[0], "exit") == 0) {
        printf("exit: Exits the shell session.\n");
        printf("Usage: exit\n");
        printf("Description: Terminates the shell session and closes the terminal. It saves the session and history before exiting.\n");
    } else if (strcmp(args[0], "set") == 0) {
        printf("set: Sets a shell environment variable.\n");
        printf("Usage: set [variable_name] [value]\n");
        printf("Description: Assigns a value to the specified environment variable.\n");
        printf("Example: set PATH=/usr/local/bin\n");
    } else if (strcmp(args[0], "unset") == 0) {
        printf("unset: Unsets or removes a shell environment variable.\n");
        printf("Usage: unset [variable_name]\n");
        printf("Description: Deletes the specified environment variable. Once unset, the variable no longer exists in the shell.\n");
        printf("Example: unset PATH\n");
    } else if (strcmp(args[0], "echo") == 0) {
        printf("echo: Prints text to the terminal.\n");
        printf("Usage: echo [string]\n");
        printf("Description: Prints the given string to the terminal. It can be used to display messages or output the value of environment variables.\n");
        printf("Example: echo \"Hello, world!\"\n");
    } else if (strcmp(args[0], "help") == 0) {
        printf("help: Displays information about built-in commands.\n");
        printf("Usage: help [command_name]\n");
        printf("Description: Shows a brief description of a built-in command. If no command is provided, a list of available commands will be displayed.\n");
        printf("Example: help cd\n");
    } else if (strcmp(args[0], "history") == 0) {
        printf("history: Displays the command history.\n");
        printf("Usage: history\n");
        printf("Description: Lists the previously executed commands with a number next to each one. Useful for reviewing and re-running old commands.\n");
    }
}
void myecho(char* args[]) {
    int i = 1;  
    while (args[i] != NULL) {
        if (args[i][0] == '$') { 
            char* var_name = args[i] + 1; 
            int found = 0;

            for (int j = 0; j < var_count; j++) {
                if (strcmp(variables[j].key, var_name) == 0) {
                    printf("%s ", variables[j].value); 
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Undefined variable: %s ", var_name);
            }
        } else {
            printf("%s ", args[i]); 
        }
        i++;
    }
    printf("\n");  
}
