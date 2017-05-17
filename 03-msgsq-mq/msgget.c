#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/msg.h>
struct msgbuf {
       long mtype;       /* message type, must be > 0 */
       char mtext[1];    /* message data */
   };

int main(){
	int id = msgget(IPC_PRIVATE,O_CREAT|O_RDWR|0644);
	if(-1 == id){
		perror("msgget error");
		return 1;
	}
	char str[] = "this is msg";
	struct msgbuf* buf = malloc(sizeof(str)+sizeof(long));
	buf->mtype= 10;
	strcpy(buf->mtext,str);
	if(fork()){
		msgsnd(id,buf,sizeof(str),0);
	}else{
		sleep(1);
		bzero(buf,sizeof(str)+sizeof(long));
		msgrcv(id,buf,sizeof(str),-11,0);
		printf("recv :%s",buf->mtext);
	}
	//msgctl(id,IPC_RMID,NULL);
}

