#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	int ret;
	printf("caller1:pid=%d, ppid = %d\n",getpid(), getppid());
	ret = system("/home/naguangqi/ngqgit/linuxprogram/week9_2/code/test1");
	printf("after calling!\n");
	sleep(3);
	return 0;
}
