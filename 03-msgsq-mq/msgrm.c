#include <stdio.h>
#include <sys/msg.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
	int id = msgget(ftok(argv[1],1),0);
	if(-1 == id){
		perror("msgget error");
		return 1;
	}
	if(-1 == msgctl(id,IPC_RMID,NULL)){
		perror("fcntl error");
		return 1;
	}
}
