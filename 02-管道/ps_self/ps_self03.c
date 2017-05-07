#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	int fd[2];
	pipe(fd);
	
	if(!fork()){
		dup2(fd[1],STDOUT_FILENO);
		execlp("ps","ps","-o","pid,ppid,stat,cmd",0);
	}else{
		if(!fork()){
			dup2(fd[0],STDIN_FILENO);
			char buf[128] = {0};
			sprintf(buf,"%d",getppid());
			execlp("grep","grep",buf,0);
		}else{
			wait(NULL);
			wait(NULL);	
		}
	}
	close(fd[0]);
	close(fd[1]);
}
