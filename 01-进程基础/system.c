#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc,char** argv){
	printf("PID:%d\n",getpid());	
	system("sleep 3&");
	printf("PID:%d\n",getpid());	
}

