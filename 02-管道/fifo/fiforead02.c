#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("/tmp/test",O_RDONLY|O_NONBLOCK);
	if(-1 == fd){
		perror("open error");
		return 1;
	}
	char buf[BUFSIZ];
	bzero(buf,BUFSIZ);
	read(fd,buf,BUFSIZ);
	printf("read:%s\n",buf);
}

