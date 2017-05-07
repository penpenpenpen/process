#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	if(-1 == mkfifo("/tmp/test",0644)){
		perror("mkfifo error");
		return 1;
	}
}

