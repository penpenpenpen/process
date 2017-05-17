#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mqueue.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#define FILE_MODE (S_IWUSR|S_IRUSR|S_IRGRP|S_IROTH) //0644
int main(int argc,char* argv[]){
	int c,flags=O_WRONLY;
	while((c=getopt(argc,argv,"n"))!=-1){
		switch(c){
		case 'n':
			flags|=O_NONBLOCK;
			break;
		}
	}
	if(optind != argc-1){
		printf("usage:%s [-n] <mqname> <message> <prio>\n");
		return 1;
	}
	mqd_t mqd = mq_open(argv[optind],flags);
	if(-1 == mqd){
		perror("mq_open error");
		return 1;
	}
	if(-1 == mq_send(mqd,argv[optind+1],strlen(argv[optind+1])+1,atoi(argv[optind+2]))){
		perror("mq_send error");
		return 1;
	}
}

