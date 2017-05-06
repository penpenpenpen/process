#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	printf("PID:%d,PPID:%d\n",getpid(),getppid());
	
	//exit(EXIT_FAILURE);
	abort();
}
