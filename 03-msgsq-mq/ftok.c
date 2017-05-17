#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char* argv[]){
	printf("%s = %ld",argv[1],ftok(argv[1],1));
}
