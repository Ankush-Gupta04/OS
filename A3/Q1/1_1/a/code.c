# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>

# define n 5


pthread_t gyani[n];
pthread_mutex_t forks[n];

void *khana(void * t){
	int k = (int *)t;
	printf("\nPhilosopher %d is thinking",k);
	pthread_mutex_lock(&forks[(k+1)%n]);
	pthread_mutex_lock(&forks[k]);
	printf("\nPhilosopher %d is eating ",k);
	sleep(5);
	pthread_mutex_unlock(&forks[(k+1)%n]);
	pthread_mutex_unlock(&forks[k]);
	printf("\nPhilosopher %d Finished eating ",k);
}

int main(){
	int i = 0;
	int k = 0;
	void *prompt;
	for (i = 1 ; i <= n ; i++){
		k = pthread_mutex_init(&forks[i],NULL);
		if (k == -1){
			perror("Reason: ");
			exit(1);
		}
	}
	for (i = 1 ; i <= n ; i++){
		k = pthread_create(&gyani[i],NULL,(void *)khana,(void *)i);
		if(k!=0){
			perror("Reason2: ");
			exit(1);
		}
	}
	for(i=1 ; i<=5 ; i++){
		k = pthread_join(gyani[i],&prompt);
		if(k!=0){
			perror("Reason: ");
			exit(1);
		}
	}
	for(i=1 ; i<=5 ; i++){
		k = pthread_mutex_destroy(&forks[i]);
		if(k!=0){
			perror("reason3: ");
			exit(1);
		}
	}
	return 0;
}
