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


#define LOOP 10000000
#define NUM 4
#define NT 100

