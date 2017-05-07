#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("/tmp/test",O_WRONLY);
	if(-1 == fd){
		perror("open error");
		return 1;
	}
	char str[] = "Hello fifo";
	fcntl(fd,F_SETFL,O_NONBLOCK);
	write(fd,str,sizeof(str));
	printf("write:%s\n",str);
}

