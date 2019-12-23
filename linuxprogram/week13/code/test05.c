#include"my.h"

void main(){
	pid_t p1, p2, p3;
	
	p1 = fork();

	if (p1 < 0)   
        printf("error in fork!");   
    else if (p1 == 0) {  
        printf("i am the child process, my process id is %d\n",getpid());   
        printf("我是爹的儿子1\n");//对某些人来说中文看着更直白。  
    }  
    else {  
        printf("i am the parent process, my process id is %d\n",getpid());   
        printf("我是孩子他爹\n");  
		p2 = fork();
			if (p2 < 0)   
        		printf("error in fork!");   
  			else if (p2 == 0) {  
				printf("i am the child process, my process id is %d\n",getpid());   
				printf("我是爹的儿子2\n");//对某些人来说中文看着更直白。  
			}  
			else {  
				//printf("i am the parent process, my process id is %d\n",getpid());   
				//printf("我是孩子他爹\n");  
				p3 = fork();
				if (p3 < 0)   
					printf("error in fork!");   
				else if (p3 == 0) {  
					printf("i am the child process, my process id is %d\n",getpid());   
					printf("我是爹的儿子3\n");//对某些人来说中文看着更直白。  
					//wait(&p1);
					//wait(&p2);
					//wait(&p3);
				}  
				
			} 
    } 
}
