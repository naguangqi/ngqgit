#include "my.h"

int zero = 0;

int main(){
	int pid, s;
	//int pid1, pid2, pid3, s1, s2, s3;
	if((pid=fork()) == 0){
		exit(0);
	}
	if((pid=fork()) == 0){
		abort();
	}
	if((pid=fork()) == 0){
		s = s/zero;
		exit(0);
	}
	/*pid1 = wait(&s1);
	pid2 = wait(&s2);
	pid3 = wait(&s3);
	pr_exit(s1, pid1);
	pr_exit(s2, pid2);
	pr_exit(s3, pid3);*/

	while((pid=wait(&s))>0) pr_exit(s, pid);
	perror("wait over!");

	exit(0);

}
