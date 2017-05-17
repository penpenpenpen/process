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
	if(optind != argc - 2){
		printf("usage:%s [-n] <pathname> <type>\n",argv[0]);
		return 1;
	}

	int id = msgget(ftok(argv[optind],1),O_RDONLY);

	if(-1 == id){
		perror("msgget error");
		return 1;
	}
	size_t msglen = BUFSIZ;
	struct msgbuf* buf = malloc(sizeof(long)+msglen);
	
	if(-1 == msgrcv(id,buf,msglen,atoi(argv[optind+1]),flag)){
		perror("fcntl error");
		return 1;
	}
	printf("read:%s",buf->mtext);
}
