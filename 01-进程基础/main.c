#include <stdio.h>
#include <unistd.h>

int main(){
	printf("PID:%d,PPID:%d\n",getpid(),getppid());
	
	return 100;
}
