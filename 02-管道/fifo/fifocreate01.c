#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char **argv){
	int c,mode=0644;
	while((c = getopt(argc,argv,"t:"))!=-1){
		switch(c){
		case 't':
			mode = strtol(optarg,NULL,8);
			break;
		}	
	}
	
	if(optind != argc - 1){
		printf("usage:%s [-t <mode>] <pathname>\n",argv[0]);
		return 1;
	}
	if(-1 == mkfifo(argv[optind],mode)){
		perror("mkfifo error");
		return 1;
	}
}

