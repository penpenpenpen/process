#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#define FILE_MODE (S_IWUSR|S_IRUSR|S_IRGRP|S_IROTH) //0644
int main(int argc,char* argv[]){
	int c,flags=O_RDONLY;
	while((c=getopt(argc,argv,"n"))!=-1){
		switch(c){
		case 'n':
			flags|=O_NONBLOCK;
			break;
		}
	}
	if(optind != argc-1){
		printf("usage:%s [-n] <mqname>\n");
		return 1;
	}
	mqd_t mqd = mq_open(argv[optind],flags);
	if(-1 == mqd){
		perror("mq_open error");
		return 1;
	}
	char buf[BUFSIZ];
	int prio;
	if(-1 == mq_receive(mqd,buf,BUFSIZ,&prio)){
		perror("mq_send error");
		return 1;
	}
	printf("msg:%s\nprio:%d\n",buf,prio);
}

