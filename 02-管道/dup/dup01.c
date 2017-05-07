#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	int fd = dup(STDOUT_FILENO);
	fprintf(fdopen(fd,"w"),"%d printf:Hello dup\n",fd);
}
