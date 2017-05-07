#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE* fd = popen("wc","w");
	//FILE* fd = popen("ls -l","r");
	//char str[] = "123 456";		
	char str[] = "123 456\n";		
	size_t n = fwrite(str,sizeof(char),sizeof(str),fd);
	if(n > sizeof(str)){
		fprintf(stderr,"FILE:%d,LINE:%d-fwrite error",__FILE__,__LINE__);
		exit(EXIT_FAILURE);
	}
	pclose(fd);
}
