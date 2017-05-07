#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_MODE (S_IWUSR|S_IRUSR|S_IRGRP|S_IROTH)

int main(){
	int fd = open("./test",O_CREAT|O_RDWR,FILE_MODE); 
	char str[]="Hello dup\n";
	dup2(fd,STDOUT_FILENO);
	printf("%d printf:Hello dup\n",fd);
}
