#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#define FILE_MODE (S_IWUSR|S_IRUSR|S_IRGRP|S_IROTH) //0644
int main(int argc,char* argv[]){
	int c,flag=0;
	long maxmsg = 10;
	long msglen = 8192;
	while((c=getopt(argc,argv,"q:l:"))!=-1){
		switch(c){
		case 'q':
			maxmsg = atoi(optarg);
			break;
		case 'l':
			msglen = atoi(optarg);
			break;
		}
	}

	if(optind != argc-1){
		printf("usage:%s [-q <maxmsg>] [-l <msglen>] <mqname>\n",argv[0]);
		return 1;
	}
	struct mq_attr attr;
	attr.mq_maxmsg = maxmsg;
	attr.mq_msgsize = msglen;
	mqd_t mqd = mq_open(argv[optind],O_CREAT,FILE_MODE,&attr);
	if(-1 == mqd){
		perror("mq_open error");
		return 1;
	}
}
