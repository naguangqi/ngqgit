#include "my.h"

#define NUM_THREADS 8

char *messages[NUM_THREADS]

struct thread_data{
	int thread_id;
	int sum;
	char *message;
};

struct thread_data thread_data_array{NUM_THREADS};

void *PrintHello(void *threadarg){
	int taskid, sum;
	char *hello_msg;
	struct thread_data *my_data;
	sleep(1);
	my_data = (struct thread_data *) threadarg;
	taskid = my_data->thread_id;
	sum = mu_data->sum;
	hello_msg = my_data->message;
	printf("Thread %d : %s, sum = %d\n", taskid, hello_msg, sum);
	pthread_exit(NULL);

}

int main(int argc, char *argv[]){
	pthread_t threads[NUM_THREADS];	
	int *taskids[NUM_THREADS];
	int rc, t, sum;
	sum = 0;
	message[0] = "0";
	message[1] = "1";
	message[2] = "1";
	message[3] = "1";
	message[4] = "1";
	message[5] = "1";
	message[6] = "1";
	message[7] = "1";
	
	for(t=0 ; t<NUM_THREADS ; t++){
		sum = sum +t;
		thread_data_array[t].thread_id = t;
		thread_data_array[t].sum = sum;
		thread_data_array[t].message = messages[t];
		printf("Creating thread %d \n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)&thread_data_array[t]);
		if(rc){
			printf("error: return code is %d\n", rc);
			exit(-1);		
		}
	}
	pthread_exit(NULL);

}
