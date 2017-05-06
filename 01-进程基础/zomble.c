#include <stdio.h>
#include <unistd.h>
#include <wait.h>
void handle(int sig){
	//wait(NULL);
	printf("this is child exit %d",sig);
}
int main(){
	signal(SIGCHLD,handle);
	printf("PID:%d,PPID:%d\n",getpid(),getppid());
	pid_t pid = fork();
	if(pid == 0){// child
		printf("this is child\n");
		printf("res:%d,PID:%d,PPID:%d\n",pid,getpid(),getppid());
	}else{
		printf("this is father\n");
		printf("res:%d,PID:%d,PPID:%d\n",pid,getpid(),getppid());
		for(;;);
	}
}
