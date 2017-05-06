#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(){
	printf("PID:%d,PPID:%d\n",getpid(),getppid());
	pid_t pid = fork();
	if(pid == 0){// child
		sleep(2);
		printf("this is child\n");
		printf("res:%d,PID:%d,PPID:%d\n",pid,getpid(),getppid());
		//exit(0);
	}else{
		printf("this is father\n");
		printf("res:%d,PID:%d,PPID:%d\n",pid,getpid(),getppid());
		printf("pid:%d exit\n",waitpid(pid,NULL,0));
	}
}
