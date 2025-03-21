#ifndef MYHSHELL
#define MYHSHELL

#define MAXSIZE 1024
#define PATH_MAX 500
#define HISTORYSIZE 5
#define MAX_VARIABLE 100



typedef struct {
    char* key;
    char* value;
} keyvalue;

extern int var_count; 
keyvalue variables[MAX_VARIABLE]; 

void mycd(char* path);
void loop();
void mypwd();
void myexecute(char* args[]);
void myexit();
void myecho(char* args[]);
void myhelp(char* args[]);
int myhistorycall();
void myhistory_write(char* command, int fd);
void myhistory_read(int fd);
void set_variable(char* key, char* value);
void unset_variable(char* key);
void handle(int sig);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#endif
