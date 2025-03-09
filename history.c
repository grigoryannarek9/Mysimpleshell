#include "shell.h"
int myhistorycall(){
    int fd = open("history.txt",O_CREAT|O_RDWR|O_APPEND,0666);
    if(fd<0){
        perror("File failed");
        return -1;
    }

    return fd;
}
void myhistory_write(char*command,int fd){
    ssize_t max_size;
    write(fd,command, strlen(command));
    write(fd,"\n",1);
    //max_size = lseek(fd,0,SEEK_END);
    // if(max_size==5){
    //     lseek(fd,0,SEEK_SET);
    //     write(fd,command, strlen(command));
    //     write(fd,"\n",1);
    // }
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