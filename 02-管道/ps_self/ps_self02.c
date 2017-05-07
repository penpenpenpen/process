#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE* readfd = popen("ps -o pid,ppid,stat,cmd","r");
	char buf[BUFSIZ]={0};
	fread(buf,sizeof(char),sizeof(buf),readfd);
	fclose(readfd);
	char cmd[128]={0};
	sprintf(cmd,"grep %d",getpid());
	FILE* writefd = popen(cmd,"w");
	fwrite(buf,sizeof(char),strlen(buf),writefd);
	fclose(writefd);
}
