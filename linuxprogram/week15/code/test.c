#include "my.h"

int main(){
	pthread_t threads[3];
	pthread_attr_t attr;
	pthread_mutex_init(&count_mutex, NULL);
	pthread_cond_init(&count_threshold_cv, NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CTREATE_JOINABLE);
	pthread_create(&threads[0], &attr, inc_count, (void *)&thread_ids[0]);
	pthread_create(&threads[1], &attr, inc_count, (void *)&thread_ids[1]);
	pthread_create(&threads[2], &attr, watch_count, (void *)&thread_ids[2]);

	for(i=0 ; i<NUM_THREADS ; i++){
		pthread_join_(threads[i], NULL);
	}
	printf("Main() : Waited on %d threads. Done.\n", NUM_THREADS);
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_threshold_cv);
	phtread_exit(NULL);
}
