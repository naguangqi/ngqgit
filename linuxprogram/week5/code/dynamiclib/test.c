#include "lib.h"
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main()
{
    
    int a[10];
	void *handle;
	void (*f1)();
	int (*f2)(), (*f3)();
	char* error;

	handle = dlopen("/home/naguangqi/ngqgit/linuxprogram/week6/code/  			dynamiclib/dlib.so", RTLD_LAZY);
	
	if(!handle){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	f1 = dlsym(handle, "urand");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);	
	}
	f2 = dlsym(handle, "max");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);	
	}
	f3 = dlsym(handle, "sum");
	if((error = dlerror()) != NULL){
		fprintf(stderr, "%s\n", dlerror());
		exit(1);	
	}
	f1(a, 10);
	printf("max=%d",f2(a,10));
    printf("sum=%d\n",f3(a,10));

    //urand(a,10);
    //printf("max=%d",max(a,10));
    //printf("sum=%d\n",sum(a,10));

	if(dlclose(handle)<0){
		fprintf(stderr, "%s\n", dlerror());	
	}

}
