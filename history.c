#include "shell.h"
int myhistorycall(){
    int fd = open("/tmp/history.txt", O_RDWR | O_CREAT | O_APPEND, 0666);
    if(fd < 0){
        perror("File failed");
        return -1;
    }
    return fd;
}

void myhistory_write(char*command,int fd){   
    char buffer[MAXSIZE];
    write(fd,command, strlen(command));
    write(fd,"\n",1);
    fsync(fd);
}
void myhistory_read(int fd) {
    char buff[MAXSIZE];
    ssize_t byteread;

    lseek(fd, 0, SEEK_SET);  

    while ((byteread = read(fd, buff, sizeof(buff))) > 0) {
        buff[byteread] = '\0';  
        printf("%s", buff);     
    }
}