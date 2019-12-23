#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include <signal.h>
#include<sys/types.h>
#include<sys/param.h>
#include<string.h>
#include<unistd.h>

#include<errno.h>
#include<wait.h>
#include<fcntl.h>

#include <time.h>

#include <sys/syscall.h>
#include <signal.h>
#include <pthread.h>


#include <assert.h>
#include <limits.h>
//#include "err_exit.h"

#define err_exit(MESSAGE) (perror(MESSAGE), exit(1))

#define check_error(return_val, msg){\
		if(return_val != 0){\
			fprintf(stderr, "%s : %s\n", msg, strerror(return_val));\
			exit(-1);\
		}\
	}\


