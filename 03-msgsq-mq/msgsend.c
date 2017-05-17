#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <fcntl.h>

struct msgbuf{
	long mtype;
	char mtext[1];
};

int main(int argc,char* argv[]){
	int c,flag = 0;
	while((c = getopt(argc,argv,"n")) !=-1){
		switch(c){
		case 'n':
			flag=IPC_NOWAIT;
			break;
		}
	}
	if(optind != argc - 3){
		printf("usage:%s [-n] <pathname> <message> <type>\n",argv[0]);
		return 1;
	}

	int id = msgget(ftok(argv[optind],1),O_WRONLY);
	if(-1 == id){
		perror("msgget error");
		return 1;
	}
	size_t msglen = strlen(argv[optind+1])+1;
	struct msgbuf* buf = malloc(sizeof(long)+msglen);
	buf->mtype = atoi(argv[optind+2]);
	strcpy(buf->mtext,argv[optind+1]);
	
	if(-1 == msgsnd(id,buf,msglen,flag)){
		perror("fcntl error");
		return 1;
	}
}
