#include "shell.h"

void myexecute(char* args[]) {
        int fd = open("/tmp/history.txt", O_RDWR | O_CREAT | O_APPEND, 0666);

    if (strcmp(args[0], "exit") == 0) {
        myexit();
    } else if (strcmp(args[0], "pwd") == 0) {
        mypwd();
    } else if (strcmp(args[0], "cd") == 0) {
        mycd(args[1]);
    } else if (strcmp(args[0], "echo") == 0) {
        myecho(args);
    } else if (strcmp(args[0], "help") == 0) {
        myhelp(args);
    }else if(strcmp(args[0],"history")==0){
        myhistory_read(fd);
    }
    else if (strcmp(args[0], "set") == 0) {
        if (args[1] == NULL) {
            printf("Error: Missing key=value pair.\n");
            return;
        }

        char* key = strtok(args[1], "="); 
        char* value = strtok(NULL, "=");

        if (key == NULL || value == NULL) {
            printf("Error: Invalid format. Use key=value.\n");
            return;
        }

        set_variable(key, value); 
    }
    else if(strcmp(args[0],"unset")==0){
        unset_variable(args[1]);
    }
}
