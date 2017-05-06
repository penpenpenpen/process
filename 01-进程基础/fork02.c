#include <stdio.h>
#include <unistd.h>
int i = 100;
int main(){
	int j=100;
	pid_t pid = fork();
	if(pid == 0){// child
		int k;
		for(k=0;k<10000;k++)
			printf("this is childi%d\t j%d\n",++i,++j);
	}else{
		int k;
		for(k=0;k<10000;k++)
			printf("this is fatheri%d\t j%d\n",--i,--j);
	}
}
