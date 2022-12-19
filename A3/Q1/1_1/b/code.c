# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>

# define n 5

int state[n];
int profs[n] = {0,1,2,3,4};

sem_t mutex;
sem_t ids[n];

void bitching(int index){
	int left = (index+4) % n;
	int right = (index + 1) % n;
	if (state[index] == 1 && state[left] != 0 && state[right] != 0){
		state[index] = 0; // eating
		sleep(2);
		printf("Philosopher %d is Eating\n", index + 1);
		sem_post(&ids[index]);
	}

}

void* khannna(void* index){
	int i = (int *)index;
		sem_wait(&mutex);
		state[i] = 1; // humgry
		printf("Philosopher %d is Hungry\n", i + 1);
		bitching(i);
		sem_post(&mutex);
		sem_wait(&ids[i]);
		sleep(1);

		sleep(0);

		sem_wait(&mutex);
		state[i] = 2; // finished eating
		printf("Philosopher %d is finished eating\n", i + 1);
		int left = (i + 4) %n;
		int right = (i + 1) % n;
		bitching(left);
		bitching(right);

		sem_post(&mutex);
}

int main(){
	int i = 0 ; 
	pthread_t threads[n];
	sem_init(&mutex, 0 , 1);
	for ( i = 0 ; i < n ; i ++){
		sem_init(&ids[i] , 0 , 0);
	}
	for ( i = 0 ; i < n ; i++){
		pthread_create(&threads[i],NULL,khannna,(void *)profs[i]);
		printf("Philosopher %d is thinking\n", i + 1);
	}
	for( i = 0 ; i < n; i++){
		pthread_join(threads[i],NULL);
	}
	return 0;
}
