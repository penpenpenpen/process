#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
	key_t key = ftok(argv[1],1);
	if(-1 == key){
		perror("ftok error");
		return 1;
	}
	int id = msgget(ftok(argv[1],1),O_RDWR);
	if(-1 == id){
		perror("msgget error");
		return 1;
	}
	struct msqid_ds ds; 
	msgctl(id,IPC_STAT,&ds);
	printf("msg_qnum:%ld msg_qsize:%ld msg_cbyte:%ld",ds.msg_qnum,ds.msg_qbytes,ds.__msg_cbytes);
}
