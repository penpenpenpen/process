#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int fd[2];
	pipe(fd);
	char in[] = "Hello pipe";
	write(fd[1],in,sizeof(in));
	printf("write:%s\n",in);

	char out[sizeof(in)]={0};
	ssize_t n = read(fd[0],out,sizeof(out));
	if(-1 == n){
		perror("read error");
		return -1;
	}
	printf("read:%s\n",out);

	close(fd[0]);
	close(fd[1]);
}
