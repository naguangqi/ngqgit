#include "my.h"

void *ProducerThread(void *pvArg)
{
    pthread_detach(pthread_self());
    int dwThrdNo = (int)pvArg;
    while(1)
    {
        pthread_mutex_lock(&gtQueLock);
        while(IsQueFull(&gtQueue))  //队列由满变为非满时，生产者线程被唤醒
            pthread_cond_wait(&gtPrdCond, &gtQueLock);

        EnterQue(&gtQueue, GetQueTail(&gtQueue)); //将队列元素下标作为元素值入队
        if(QueDataNum(&gtQueue) == 1) //当生产者开始产出后，通知(唤醒)消费者线程
            pthread_cond_broadcast(&gtCsmCond);
        printf("[Producer %2u]Current Product Num: %u\n", dwThrdNo, QueDataNum(&gtQueue));

        pthread_mutex_unlock(&gtQueLock);
        sleep(rand()%DELAY_TIME + 1);
    }
}

void *ConsumerThread(void *pvArg)
{
    pthread_detach(pthread_self());
    int dwThrdNo = (int)pvArg;
    while(1)
    {
        pthread_mutex_lock(&gtQueLock);
        while(IsQueEmpty(&gtQueue)) //队列由空变为非空时，消费者线程将被唤醒
            pthread_cond_wait(&gtCsmCond, &gtQueLock);

        if(GetQueHead(&gtQueue) != GetQueHeadData(&gtQueue))
        {
            printf("[Consumer %2u]Product: %d, Expect: %d\n", dwThrdNo,
                   GetQueHead(&gtQueue), GetQueHeadData(&gtQueue));
            exit(0);
        }  
        LeaveQue(&gtQueue);
        if(QueDataNum(&gtQueue) == (PRD_NUM-1)) //当队列由满变为非满时，通知(唤醒)生产者线程
            pthread_cond_broadcast(&gtPrdCond);
        printf("[Consumer %2u]Current Product Num: %u\n", dwThrdNo, QueDataNum(&gtQueue));

        pthread_mutex_unlock(&gtQueLock);
        sleep(rand()%DELAY_TIME + 1);
    }
}
