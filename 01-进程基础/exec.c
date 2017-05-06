#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char ** environ;

int main(int argc,char** argv){
	
	//execv()
	//execvp()
	//execve()
	printf("%s,PID %d\n",argv[0],getpid());
	//execl("/bin/ps","ps","-a","-o","pid,ppid,cmd",0);
	//execlp("ps","ps","-a","-o","pid,ppid,cmd",0);
	//execle("/bin/ps","ps","-a","-o","pid,ppid,cmd",0,environ);
	char* args[] = {"ps","-a","-o","pid,ppid,cmd",0};
	//execv("/bin/ps",args);
	execve("/bin/ps",args,environ);
	//execvp("ps",args);
	printf("%s,PID %d\n",argv[0],getpid());
	//execlp()
	//execle()
}
