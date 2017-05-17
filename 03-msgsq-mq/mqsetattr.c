#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(){
	mqd_t mqd = mq_open("/tmp.test",O_RDWR);
	if(-1 == mqd){
		perror("mq_open error");
		return;
	}
	struct mq_attr new_attr;
	bzero(&new_attr,sizeof(new_attr));

	new_attr.mq_flags = O_NONBLOCK;
	struct mq_attr attr;
	if(-1 == mq_setattr(mqd,&new_attr,&attr)){
		perror("mq_setattr error");
		return 1;
	}
	printf("flag:%ld,Max msg:%ld,Max msgsize:%ld,Cur msgnun:%ld\n",attr.mq_flags,attr.mq_maxmsg,attr.mq_msgsize,attr.mq_curmsgs);
}

