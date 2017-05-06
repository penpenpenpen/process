#include <stdio.h>
#include <unistd.h>

int main(){
	printf("PID:%dPPID:%d\n",getpid(),getppid());
	for(;;);
}
