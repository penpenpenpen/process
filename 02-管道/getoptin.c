#include <stdio.h>
#include <unistd.h>

int main(int argc,char** argv){
	int c;
	while((c = getopt(argc,argv,"ab:"))!=-1){
		switch(c){
		case 'a':
			printf("option a\n");
			break;
		case 'b':
			printf("option b %s\n",optarg);
			break;
		default:
			perror("getopt error");
			return 1;
		}
	}
	if(optind != argc -1){
		printf("usage:%s getoption [-a] [-b <optarg>] <argument>\n",argv[0]);
		return 1;
	}
	printf("argument:%s\n",argv[optind]);

}
