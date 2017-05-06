#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void handler(int sig){
	int status;
	pid_t cpid = wait(&status);
 	if(WIFEXITED(status)){
		printf("child exit by %d\n",WEXITSTATUS(status));
	}	
	if(WIFSIGNALED(status)){
		printf("child exit by signal %d\n",WTERMSIG(status));
	}
	printf("child %d exit\n",cpid);
}

int main(){
	signal(SIGCHLD,handler);
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
		printf("leave:%d\n",sleep(5));
		//exit(200);
	}
	for(;;);
}
