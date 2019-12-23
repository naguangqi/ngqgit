#include"my.h"

int main(){
	int status;
	pid_t pid;
	int k;
	pid = fork();
	if(pid<0){
		perror("forkk failed!\n");
		return -1;
	}
	else if(pid==0){
		printf("child %d : running!\n", getpid());
		exit(120);
	}
	else{
		if((k=wait(&status))!=0){
			if(WIFEXITED(status))
				printf("child exit with exit!\n exit code = %d\n", WEXITSTATUS(status));
			else if(WIFSIGNALED(status))
				printf("child terminatated with signal!\n signal number = %d\n", WTERMSIG(status));		
		}
	exit(0);
	}


}
