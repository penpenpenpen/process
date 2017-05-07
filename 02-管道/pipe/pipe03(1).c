#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(){
	int fd[2];
	pipe(fd);
	if(!fork()){// child
		char in[] = "Hello pipe";
		sleep(3);
		write(fd[1],in,sizeof(in));
		printf("child %d write:%s\n",getpid(),in);
	}else{// parent
		fcntl(fd[0],F_SETFL,O_NONBLOCK);
		char out[BUFSIZ]={0};
		ssize_t n = read(fd[0],out,sizeof(out));
		if(-1 == n){
			perror("read error");
			return -1;
		}
		printf("parent %d read:%s\n",getpid(),out);
	}
	close(fd[0]);
	close(fd[1]);
}
