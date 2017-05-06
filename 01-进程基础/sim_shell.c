#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void handle(int sig){
	wait(NULL);
}
int main(){
	printf("welcome to sim shell\n");
	//
	signal(SIGCHLD,handle);

	for(;;){
		printf(">");
		fflush(stdout);
		char buf[BUFSIZ];
		bzero(buf,BUFSIZ);
		fgets(buf,BUFSIZ,stdin);
	        size_t n = strlen(buf);
		if(buf[n-1] == '\n'){
			buf[n-1] = '\0';
		}		
		if(strcmp(buf,"quit")==0)
			break;
		//system(buf);
		char* argv[128];
		bzero(argv,128);
		char* p = buf;
		int index = 0;
		char* temp = NULL;
		do{	
			temp =strtok(p," ");
			p = NULL;
			argv[index++] = temp;
		}while(temp != NULL);
		if(fork() == 0){
			execvp(argv[0],argv);	
		}
		//sleep(-1);
		pause();
	}	

	printf("sim shell exit\n");
	return 0;
}
