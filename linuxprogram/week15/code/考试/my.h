#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include <signal.h>
#include<sys/types.h>
#include<sys/param.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>
#include<errno.h>
#include<wait.h>
#include<fcntl.h>

#include <time.h>

#include <sys/syscall.h>
#include <signal.h>
#include <pthread.h>


#include <assert.h>
#include <limits.h>


/*
#define QUEUE_SIZE   5 //队列最大容纳QUEUE_SIZE-1个元素
*/
typedef struct{
	int aData[QUEUE_SIZE];  //队列元素
	int dwHead;  //指向队首元素
	int dwTail;  //指向队尾元素的下一个元素
}T_QUEUE, *PT_QUEUE;


#define PRODUCER_NUM   1  //生产者数
#define CONSUMER_NUM   1  //消费者数
#define PRD_NUM        5 //最多生产的产品数
#define DELAY_TIME     3  //生产(或消费)任务之间的最大时间间隔

#define QUEUE_SIZE     (PRD_NUM+1) //队列最大容纳QUEUE_SIZE-1个元素

T_QUEUE gtQueue;
pthread_mutex_t gtQueLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t gtPrdCond = PTHREAD_COND_INITIALIZER; //Full->Not Full
pthread_cond_t gtCsmCond = PTHREAD_COND_INITIALIZER; //Empty->Not Empty


void *ProducerThread(void *pvArg);
void *ConsumerThread(void *pvArg);

/*
void InitQue(PT_QUEUE ptQue);
void EnterQue(PT_QUEUE ptQue, int dwElem);
int LeaveQue(PT_QUEUE ptQue);
void DisplayQue(PT_QUEUE ptQue);
int IsQueEmpty(PT_QUEUE ptQue);
int IsQueFull(PT_QUEUE ptQue);
int QueDataNum(PT_QUEUE ptQue);
int GetQueHead(PT_QUEUE ptQue);
int GetQueHeadData(PT_QUEUE ptQue);
int GetQueTail(PT_QUEUE ptQue);
void QueueTest(void);
*/






