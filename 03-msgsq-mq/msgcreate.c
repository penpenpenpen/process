#include <stdio.h>
#include <sys/msg.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
	key_t key = ftok(argv[1],1);
	if(-1 == key){
		perror("ftok error");
		return 1;
	}
	int id = msgget(ftok(argv[1],1),IPC_CREAT|O_RDWR|0644);
	if(-1 == id){
		perror("msgget error");
		return 1;
	}
	printf("msqid:%d\n",id);
}
