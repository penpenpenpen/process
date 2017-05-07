#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("/tmp/test",O_WRONLY|O_NONBLOCK);
	if(-1 == fd){
		perror("open error");
		return 1;
	}
	char str[] = "Hello fifo";
	write(fd,str,sizeof(str));
	printf("write:%s\n",str);
}

