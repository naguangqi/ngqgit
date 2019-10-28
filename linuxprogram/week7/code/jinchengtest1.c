#include <stdio.h>
#include <unistd.h>

int main(){
	printf("pid-> %d\n", getpid());
	printf("ppid-> %d\n", getpid());
	while(1);
	return 0;
}
