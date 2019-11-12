#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<wait.h>
#include<fcnlt.h>
#include<sys/stat.h>

int g = 1;

int main(){
	int local = 1;
	int *m = malloc(sizeof(int));
	*m = 10;
	pid_t pid = fork();
	if(pid < 0){
		printf("fork failed(%s)", strerror(errno));
		return 1;	
	}
	else if(pid == 0){
		local = 9999;
		g = 9999;
		*m = 9999;
		fprintf(stderr, "[child] child change local global malloc vulue to 9999\n");
		free(m);
		sleep(10);
		fprintf(stderr, "[child] exit!\n");
		exit(0);
	}
	else{
		fprintf(stderr, "[parent] waiting child exit!\n");		
		waitpid(pid, NULL, 0);
		fprintf(stderr, "[parent] child have exit!\n");		
		fprintf(stderr, "[parent] g = %d\n", g);
		fprintf(stderr, "[parent] local = %d\n", local);
		fprintf(stderr, "[parent] *m = %d\n", g);				
	}

}


