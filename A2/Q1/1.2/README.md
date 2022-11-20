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
		int arc = execv("temp.sh",argv);
		printf("%d",arc);
		perror("hi:: ");
		sleep(2);
        	exit(EXIT_SUCCESS);
	}
	waitpid(p,NULL,0);
	if (clock_gettime(CLOCK_REALTIME, &end) == -1){
		perror("hard luck");
	}
	double a1 = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) /(double) BILLION;
	printf("%lf", a1);
	
}


