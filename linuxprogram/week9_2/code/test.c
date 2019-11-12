#include<stdlib.h>
#include<stdio.h>

static void __attribute__((constructor)) before_mian(void){
	printf("Running befored mian!\n");
}

int main(){
	printf("Main\n");
	return 0;
}
