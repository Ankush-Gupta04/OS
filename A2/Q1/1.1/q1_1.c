#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

double a1, a2, a3;

#define BILLION 1000000000L;

void *countA(void * input){
	struct timespec start, end;
	if (clock_gettime(CLOCK_REALTIME, &start) == -1){
		perror("hard luck");
	}
	int k = 0;
	for (long int i = 0; i < pow(2,32); i++){
		k = 1;
	}
	if (clock_gettime(CLOCK_REALTIME, &end) == -1){
		perror("hard luck");
	}
	a1 = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) /(double) BILLION;
	return NULL;
} 

void *countB(void * input){
	struct timespec start, end;
	if (clock_gettime(CLOCK_REALTIME, &start) == -1){
		perror("hard luck");
	}
	int k = 0;
	for (long int i = 0; i < pow(2,32); i++){
		k = 1;
	}
	if (clock_gettime(CLOCK_REALTIME, &end) == -1){
		perror("hard luck");
	}
	a2 = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / (double)BILLION;
	return NULL;
}

void *countC(void * input){
	struct timespec start, end;
//	printf("H\n");
	if (clock_gettime(CLOCK_REALTIME, &start) == -1){
		perror("hard luck");
	}
	int k = 0;
	for (long int i = 0; i < pow(2,32); i++){
		k = 1;
	}
	if (clock_gettime(CLOCK_REALTIME, &end) == -1){
		perror("hard luck");
	}
	a3 = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / (double)BILLION;
	return NULL;
}

int main(){
	FILE * x,* y, *z;
	x = fopen("othr_reading.txt","a");
	y = fopen("fifo_reading.txt","a");
	z = fopen("rr_reading.txt","a");
	int n = 0;
	for (int i = 0 ; i < 10; i++){
		pthread_t tid1;
		pthread_t tid2;
		pthread_t tid3;

		struct sched_param param;
		param.sched_priority = 0;

		pthread_create(&tid1,NULL,&countA,NULL);
		int ret = pthread_setschedparam(tid1, SCHED_OTHER, &param);
		if (ret != 0){
			printf("problem");
			printf("%d ",ret);
			perror("h\n");
		}

		pthread_create(&tid2,NULL,&countB,NULL);
		struct sched_param param1;
		param1.sched_priority = 45 - n;
		ret = pthread_setschedparam(tid2, SCHED_FIFO,&param1);
		if (ret != 0){
			perror("hi");
		}
	
		int a = pthread_create(&tid3,NULL,&countC,NULL);
		if (a != 0){
			perror("ho: ");
			printf("ho");
		}
		struct sched_param param2;
		param2.sched_priority = 46 - n;
		ret = pthread_setschedparam(tid3, SCHED_RR, &param2);
		if (ret != 0){
			perror("hi");
		}

		pthread_join(tid1,NULL);
		pthread_join(tid2,NULL);
		pthread_join(tid3,NULL);
		
		fprintf(x,"%lf\n",a1);
		fprintf(y,"%lf\n",a2);
		fprintf(z,"%lf\n",a3);
	
		printf("%lf %lf %lf\n",a1,a2,a3);
		n++;
	}
	fclose(x);
	fclose(y);
	fclose(z);
	return 0;
}
