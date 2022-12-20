# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>

# define n 5


pthread_t gyani[n];
pthread_mutex_t forks[n];
pthread_mutex_t bowls[2];
int bowl[2] = {0,0};

void *khana(void * t){
	int k = (int *)t;
    int bowl_no;
    if (bowl[0] == 0){
        bowl_no = 0;
        bowl[0] = 1;
    }
    else{
        bowl_no = 1;
        bowl[1] = 1;
    }
	printf("Philosopher %d is thinking\n",k);
	pthread_mutex_lock(&forks[(k+1)%n]);
	pthread_mutex_lock(&forks[k]);
    pthread_mutex_lock(&bowls[bowl_no]);
	printf("Philosopher %d is eating\n",k);
	sleep(5);
	pthread_mutex_unlock(&forks[(k+1)%n]);
	pthread_mutex_unlock(&forks[k]);
    pthread_mutex_unlock(&bowls[bowl_no]);
	printf("Philosopher %d Finished eating\n",k);
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
    k = pthread_mutex_init(&bowls[0],NULL);
    if (k == -1){
        perror("Reason: ");
        exit(1);
    }
    k = pthread_mutex_init(&bowls[1],NULL);
    if (k == -1){
        perror("Reason: ");
        exit(1);
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
    k = pthread_mutex_destroy(&bowls[0]);
    if (k == -1){
        perror("Reason: ");
        exit(1);
    }
    k = pthread_mutex_destroy(&bowls[1]);
    if (k == -1){
        perror("Reason: ");
        exit(1);
    }
	return 0;
}
