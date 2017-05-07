#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE* fd = popen("ps -ef","r");
	//FILE* fd = popen("ls -l","r");
		
	char buf[BUFSIZ];
	size_t count = 0;
	printf("read data:\n");
	do{
		memset(buf,'\0',BUFSIZ);
		size_t n = fread(buf,sizeof(char),BUFSIZ-1,fd);
		if( n > BUFSIZ - 1 ){
			perror("fread error");
			exit(EXIT_FAILURE);
		}
		count += n;
		printf("%s",n,buf);
	}while(!feof(fd));
	printf("total size:%ld\n",count);
	pclose(fd);
}
