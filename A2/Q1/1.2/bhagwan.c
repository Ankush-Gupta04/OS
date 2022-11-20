#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

#define BILLION 1000000000L;

int main(){
	char * argv[] = {"temp.sh",NULL};
	int p = fork();
	struct timespec start, end;
	if (clock_gettime(CLOCK_REALTIME, &start) == -1){
		perror("hard luck");
	}
	if (p == 0){
		int arc = execl("bash1.sh","bash1.sh",NULL);
		printf("%d",arc);
		perror("hi1:: ");
		sleep(2);
        	exit(EXIT_SUCCESS);
	}
	waitpid(p,NULL,0);

	int a = fork();
	if (a == 0){
		int arm = execl("bash1_1.sh","bash1_1.sh",NULL);
		perror("hi2::");
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	waitpid(a,NULL,0);

	if (clock_gettime(CLOCK_REALTIME, &end) == -1){
		perror("hard luck");
	}
	double aa1 = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) /(double) BILLION;
		

	if (clock_gettime(CLOCK_REALTIME, &start) == -1){
		perror("hard luck");
	}
	int p1 = fork();
	if (p1 == 0){
		int arc = execl("bash2.sh","bash2.sh",NULL);
		printf("%d",arc);
		perror("hi3:: ");
		sleep(2);
        	exit(EXIT_SUCCESS);
	}
	waitpid(p1,NULL,0);

	int a1 = fork();
	if (a1 == 0){
		int arm = execl("bash2_2.sh","bash1_1.sh",NULL);
		perror("hi4::");
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	waitpid(a1,NULL,0);

	if (clock_gettime(CLOCK_REALTIME, &end) == -1){
		perror("hard luck");
	}
	double aa2 = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) /(double) BILLION;
//	printf("%lf ", a2);


	if (clock_gettime(CLOCK_REALTIME, &start) == -1){
		perror("hard luck");
	}
	int p2 = fork();
	if (p2 == 0){
		int arc = execl("bash1.sh","bash1.sh",NULL);
		printf("%d",arc);
		perror("hi5:: ");
		sleep(2);
        	exit(EXIT_SUCCESS);
	}
	waitpid(p2,NULL,0);

	int a2 = fork();
	if (a2 == 0){
		int arm = execl("bash3_3.sh","bash1_1.sh",NULL);
		perror("hi2::");
		sleep(2);
		exit(EXIT_SUCCESS);
	}
	waitpid(a2,NULL,0);

	if (clock_gettime(CLOCK_REALTIME, &end) == -1){
		perror("hard luck");
	}
	double aa3 = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) /(double) BILLION;
	printf("%lf %lf %lf ",aa1,aa2,aa3);
	
}

