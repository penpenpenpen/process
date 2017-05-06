#include <stdio.h>
#include <unistd.h>
int i = 100;
int main(){
	int j=100;
	FILE* fd = fopen("./test","w+");
	pid_t pid = fork();
	if(pid == 0){// child
		int k;
		for(k=0;k<10000;k++)
			fprintf(fd,"this is childi%d\t j%d\n",++i,++j);
	}else{
		int k;
		for(k=0;k<10000;k++)
			fprintf(fd,"this is fatheri%d\t j%d\n",--i,--j);
	}
}
