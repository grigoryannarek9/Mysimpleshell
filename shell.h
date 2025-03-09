#ifndef MYHSHELL
#define MYHSHELL

#define MAXSIZE 1024
#define PATH_MAX 500
#define HISTORYSIZE 5

typedef struct {
    char* key;
    char* value;
} keyvalue;

void mycd(char* path);
void loop();
void mypwd();
void myexecute(char* args[], int fd); 
void myexit(int fd); 
void myecho(char* args[]);
void myhelp(char* args[]);
int myhistorycall();
void myhistory_write(char* command, int fd);
void myhistory_read(int fd);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#endif
