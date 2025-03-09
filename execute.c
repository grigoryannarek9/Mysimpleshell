#include "shell.h"

void myexecute(char* args[],int fd) {
    
    if (strcmp(args[0], "exit") == 0) {
        myexit(fd);
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
}
