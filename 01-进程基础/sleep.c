#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <strings.h>

int main(){
	int i = 0;
	for(;;){
		time_t t;
		time(&t);
		struct tm* ptm =  gmtime(&t);
		char buf[BUFSIZ];
		bzero(buf,BUFSIZ);
		strftime(buf,BUFSIZ,"%P %T",ptm);
		printf("\r%s",buf);
		fflush(stdout);
		sleep(1);
	}
}
