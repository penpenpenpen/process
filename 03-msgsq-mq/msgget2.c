#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/msg.h>
struct msgbuf {
       long mtype;       /* message type, must be > 0 */
       char mtext[1];    /* message data */
   };
#define ERR_CASE(err) case err:printf(#err);break;
int main(){
	key_t key = ftok("/tmp/abcdef",1);
	if(-1 == key){
		perror("ftok error");
		return 1;
	}	
	int id = msgget(key,IPC_CREAT|O_RDWR|0644);
	if(-1 == id){
		switch(errno){
			ERR_CASE(EACCES)
			ERR_CASE(ENOMEM)
			ERR_CASE(EEXIST)
			ERR_CASE(ENOENT)
			ERR_CASE(ENOSPC)
			default:
			printf("no err\n");
		}
		perror("msgget error");
		return 1;
	}
	char str[] = "this is msg";
	struct msgbuf* buf = malloc(sizeof(str)+sizeof(long));
	buf->mtype= 10;
	strcpy(buf->mtext,str);
	if(!fork()){
		msgsnd(id,buf,sizeof(str),0);
	}else{
		bzero(buf,sizeof(str)+sizeof(long));
		msgrcv(id,buf,sizeof(str),-11,0);
		printf("recv :%s",buf->mtext);
	}
	msgctl(id,IPC_RMID,NULL);
}

