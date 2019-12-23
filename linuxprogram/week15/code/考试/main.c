#include "my.h"



int main(void)
{
    InitQue(&gtQueue);
    srand(getpid());  //初始化随机函数发生器

    pthread_t aThrd[CONSUMER_NUM+PRODUCER_NUM];
    int dwThrdIdx;
    for(dwThrdIdx = 0; dwThrdIdx < CONSUMER_NUM; dwThrdIdx++)
    {  //创建CONSUMER_NUM个消费者线程，传入(void*)dwThrdIdx作为ConsumerThread的参数
        pthread_create(&aThrd[dwThrdIdx], NULL, ConsumerThread, (void*)dwThrdIdx);
    }
    sleep(2);
    for(dwThrdIdx = 0; dwThrdIdx < PRODUCER_NUM; dwThrdIdx++)
    {
        pthread_create(&aThrd[dwThrdIdx+CONSUMER_NUM], NULL, ProducerThread, (void*)dwThrdIdx);
    }
    while(1);
    return 0 ;
}
