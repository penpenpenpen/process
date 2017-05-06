#include <stdio.h>
#include <unistd.h>
#include <wait.h>

void handler(int sig){
	pid_t cpid = wait(NULL);
	printf("child %d exit",cpid);
}

int main(){
	signal(SIGCHLD,handler);
	printf("PID:%d,PPID:%d\n",getpid(),getppid());
	pid_t pid = fork();
	if(pid == 0){// child
		sleep(2);
		printf("this is child\n");
		printf("res:%d,PID:%d,PPID:%d\n",pid,getpid(),getppid());
	}else{
		printf("this is father\n");
		printf("res:%d,PID:%d,PPID:%d\n",pid,getpid(),getppid());
	}
}
