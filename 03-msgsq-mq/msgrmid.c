#include <stdio.h>
#include <sys/msg.h>

int main(int argc,char* argv[]){
	int i;
	for(i=1;i<argc;i++){
		msgctl(atoi(argv[i]),IPC_RMID,NULL);
	}
}
