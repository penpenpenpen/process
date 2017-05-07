#include <stdio.h>
#include <stdlib.h>

int main(){
	char cmd[128]={0};
	sprintf(cmd,"ps -p %d -o pid,ppid,stat,cmd",getpid());
	system(cmd);
}
