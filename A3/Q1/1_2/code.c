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
sem_t bowls[2];
int bowl_o[2];

void bitching(int index,int bowl_no){
	int left = (index+4) % n;
	int right = (index + 1) % n;
	if (state[index] == 1 && state[left] != 0 && state[right] != 0 && bowl_o[bowl_no] == 0){
		state[index] = 0; // eating
		bowl_o[bowl_no] = 1; // busy
		sleep(2);
		printf("Philosopher %d is Eating\n", index + 1);
		sem_post(&ids[index]);
		sem_post(&bowls[bowl_no]);
	}

}

void* khannna(void* index){
	int i = (int *)index;
	int bowl_no;
	if (bowl_o[0] == 0){
		bowl_no = 0;
	}
	else{
		bowl_no = 1;
	}
		sem_wait(&mutex);
		state[i] = 1; // humgry
		printf("Philosopher %d is Hungry\n", i + 1);
		bitching(i,bowl_no);
		sem_post(&mutex);
		sem_wait(&ids[i]);
		sem_wait(&bowls[bowl_no]);
		sleep(1);

		sleep(0);

		sem_wait(&mutex);
		state[i] = 2; // finished eating
		bowl_o[bowl_no] = 0; // vacant
		printf("Philosopher %d is finished eating\n", i + 1);
		int left = (i + 4) %n;
		if (bowl_o[0] == 0){
			bowl_no = 0;
		}
		else{
			bowl_no = 1;
		}
		bitching(left,bowl_no);

		int right = (i + 1) % n;
		if (bowl_o[0] == 0){
			bowl_no = 0;
		}
		else{
			bowl_no = 1;
		}
		bitching(right,bowl_no);

		sem_post(&mutex);
}

int main(){
	int i = 0 ; 
	pthread_t threads[n];
	sem_init(&mutex, 0 , 1);
	for ( i = 0 ; i < n ; i ++){
		sem_init(&ids[i] , 0 , 0);
	}
	for (i = 0 ; i < 2; i++){
		sem_init(&bowls[i],0,0);
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

