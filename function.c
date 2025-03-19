#include "shell.h"

void loop() {
    int fd = myhistorycall();
    char command[MAXSIZE];
    char* args[MAXSIZE];
    char username[MAXSIZE];
    
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; 

    while (1) {
        signal(SIGINT,handle);
        printf("%sshell>> ", username);
        if (!fgets(command, sizeof(command), stdin)) {
            printf("\n");
            break;
        }
        command[strcspn(command, "\n")] = '\0';
        myhistory_write(command,fd);

        char* token = strtok(command, " ");
        int i = 0;

        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (args[0] == NULL) {
            continue;
        }
        if (strcmp(args[0], "exit") == 0 || 
            strcmp(args[0], "pwd") == 0 || 
            strcmp(args[0], "cd") == 0 ||
            strcmp(args[0], "set") == 0 ||
            strcmp(args[0], "unset") == 0 ||
            strcmp(args[0], "echo") == 0 ||
            strcmp(args[0], "help") == 0 ||
            strcmp(args[0], "history") == 0) {
            myexecute(args);
            continue;
        }else{

        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            execvp(args[0], args);
            fprintf(stderr, "command not found: %s\n", args[0]);
            exit(1);  
        } else {
            wait(NULL);  
        }
    }
}
close(fd);
}
