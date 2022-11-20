#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <pthread.h>

#define BILLION 1000000000L;

int main(){
	//char * argv[] = {"temp.sh",NULL};
	struct timespec start,end1, end2,end3;
	if (clock_gettime(CLOCK_REALTIME, &start) == -1){
		perror("hard luck");
	}
	//  creating process 1  -----> bash1 ------> dowloading,untar,config,delete
	int p = fork();
	if (p == 0){
		struct sched_param pp1;
		pp1.sched_priority = 0;
		sched_setscheduler(p,SCHED_OTHER, &pp1);
		perror("policy: ");
		int arc = execl("bash1.sh","bash1.sh",NULL);
		printf("%d",arc);
		perror("hi1:: ");
		sleep(2);
        	exit(EXIT_SUCCESS);
	}


	//  creating process 2  -----> bash2 ------> dowloading,untar,config,delete
	int p1 = fork();
	if (p1 == 0){
		struct sched_param pp2;
		pp2.sched_priority = 46;
		sched_setscheduler(p, SCHED_FIFO ,&pp2);
		perror("policy: ");
		int arc = execl("bash2.sh","bash2.sh",NULL);
		printf("%d",arc);
		perror("hi3:: ");
		sleep(2);
        	exit(EXIT_SUCCESS);
	}


	//  creating process 3  -----> bash3 ------> dowloading,untar,config,delete
	int p2 = fork();
	if (p2 == 0){
		struct sched_param pp3;
		pp3.sched_priority = 48;
		sched_setscheduler(p, SCHED_RR ,&pp3);
		perror("policy: ");
		int arc = execl("bash3.sh","bash3.sh",NULL);
		printf("%d",arc);
		perror("hi5:: ");
		sleep(2);
        	exit(EXIT_SUCCESS);
	}
	
	double aa1, aa2, aa3;

	// first waitpid
	int x = waitpid(-1,NULL,0);
	if (x == p){
		if (clock_gettime(CLOCK_REALTIME, &end1) == -1){
			perror("hard luck");
		}
		aa1 = (end1.tv_sec - start.tv_sec) + (double)(end1.tv_nsec - start.tv_nsec) /(double) BILLION;
	}

	if (x == p1){
		if (clock_gettime(CLOCK_REALTIME, &end2) == -1){
			perror("hard luck");
		}
		aa2 = (end2.tv_sec - start.tv_sec) + (double)(end2.tv_nsec - start.tv_nsec) /(double) BILLION;
	}

	if (x == p2){
		if (clock_gettime(CLOCK_REALTIME, &end3) == -1){
			perror("hard luck");
		}
		aa2 = (end3.tv_sec - start.tv_sec) + (double)(end3.tv_nsec - start.tv_nsec) /(double) BILLION;
	}


	// second waitpid
	int y = waitpid(-1,NULL,0);
	if (y == p){
		if (clock_gettime(CLOCK_REALTIME, &end1) == -1){
			perror("hard luck");
		}
		aa1 = (end1.tv_sec - start.tv_sec) + (double)(end1.tv_nsec - start.tv_nsec) /(double) BILLION;
	}

	if (y == p1){
		if (clock_gettime(CLOCK_REALTIME, &end2) == -1){
			perror("hard luck");
		}
		aa2 = (end2.tv_sec - start.tv_sec) + (double)(end2.tv_nsec - start.tv_nsec) /(double) BILLION;
	}

	if (y == p2){
		if (clock_gettime(CLOCK_REALTIME, &end3) == -1){
			perror("hard luck");
		}
		aa2 = (end3.tv_sec - start.tv_sec) + (double)(end3.tv_nsec - start.tv_nsec) /(double) BILLION;
	}

	// third waitpid
	int z = waitpid(-1,NULL,0);
	if (z == p){
		if (clock_gettime(CLOCK_REALTIME, &end1) == -1){
			perror("hard luck");
		}
		aa1 = (end1.tv_sec - start.tv_sec) + (double)(end1.tv_nsec - start.tv_nsec) /(double) BILLION;
	}

	if (z == p1){
		if (clock_gettime(CLOCK_REALTIME, &end2) == -1){
			perror("hard luck");
		}
		aa2 = (end2.tv_sec - start.tv_sec) + (double)(end2.tv_nsec - start.tv_nsec) /(double) BILLION;
	}

	if (z == p2){
		if (clock_gettime(CLOCK_REALTIME, &end3) == -1){
			perror("hard luck");
		}
		aa2 = (end3.tv_sec - start.tv_sec) + (double)(end3.tv_nsec - start.tv_nsec) /(double) BILLION;
	}
	printf("%lf %lf %lf ",aa1,aa2,aa3);
	FILE *reading;
	reading = fopen("readings.txt","w");
	fprintf(reading,"%lf\n",aa1);
	fprintf(reading,"%lf\n",aa2);
	fprintf(reading,"%lf\n",aa3);
	return 0;
}
