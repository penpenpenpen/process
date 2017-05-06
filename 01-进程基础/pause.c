#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void test(int sig){
	printf("revc a signal%d",sig);
}

int main(){
	signal(SIGINT,test);
	printf("before pause\n");
	pause();
	printf("after pause\n");
}

