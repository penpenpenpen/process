#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc,char* argv[]){
	mqd_t mqd = mq_open(argv[1],O_RDONLY);
	if(-1 == mqd){
		perror("mq_open error");
		return;
	}
	struct mq_attr attr;
	mq_getattr(mqd,&attr);
	printf("flag:%ld,Max msg:%ld,Max msgsize:%ld,Cur msgnun:%ld\n",attr.mq_flags,attr.mq_maxmsg,attr.mq_msgsize,attr.mq_curmsgs);
}

