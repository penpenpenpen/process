#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_MODE (S_IWUSR|S_IRUSR|S_IRGRP|S_IROTH)

int main(){
	int fd = open("./test",O_CREAT|O_RDWR,FILE_MODE); 
	char str[]="Hello dup\n";
	write(fd,str,sizeof(str));
	int cp_fd = dup(fd);
	printf("copy %d to %d",fd,cp_fd);
	write(cp_fd,str,sizeof(str));
	//fprintf(fdopen(fd,"w"),"%d printf:Hello dup\n",fd);
	close(fd);
}
