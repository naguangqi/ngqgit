#include"my.h"

int main(){
	pid_t p1, p2, p3;
	
	p1 = fork();
	p2 = fork();
	p3 = fork();

	printf("pid = %d\n", getpid());
	exit(0);

	return 0;
}
