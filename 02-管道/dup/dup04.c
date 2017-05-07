#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define FILE_MODE (S_IWUSR|S_IRUSR|S_IRGRP|S_IROTH)
int main(){
	int save_fd = dup(STDOUT_FILENO);
	int fd = open("./test",O_CREAT|O_RDWR,FILE_MODE); 
	if(-1 == dup2(fd,STDOUT_FILENO)){
		perror("dup2 error0");
		return 1;
	}
	close(fd);
	printf("%d printf:Hello dup\n",fd);
	fflush(stdout);// 一定要清除缓冲区，否则会输出到终端
	if(-1 == dup2(save_fd,STDOUT_FILENO)){
		perror("dup2 error");
		return 1;
	}
	close(save_fd);
	printf("%d printf:this is save\n",save_fd);
}
