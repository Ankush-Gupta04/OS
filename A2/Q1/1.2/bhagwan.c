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
	struct timespec start1, end1, start2, end2, start3, end3;
	double aa1, aa2, aa3;
	if (clock_gettime(CLOCK_REALTIME, &start1) == -1){
		perror("hard luck");
	}
	if (p == 0){
		int arc = execl("bash1.sh","bash1.sh",NULL);
		printf("%d",arc);
		perror("hi1:: ");
		sleep(2);
        	exit(EXIT_SUCCESS);
	}
	else if ( p > 0){
		waitpid(p,NULL,0);
		int a = fork();
		if (a == 0){
			int arm = execl("bash1_1.sh","bash1_1.sh",NULL);
			perror("hi2::");
			sleep(2);
			exit(EXIT_SUCCESS);
		}
		else if (a > 0){
			waitpid(a,NULL,0);
			if (clock_gettime(CLOCK_REALTIME, &end2) == -1){
				perror("hard luck");
			}
			aa1 = (end1.tv_sec - start1.tv_sec) + (double)(end1.tv_nsec - start1.tv_nsec) /(double) BILLION;
			if (clock_gettime(CLOCK_REALTIME, &start2) == -1){
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
			else if (p1 > 0){
				waitpid(p1,NULL,0);
				int a1 = fork();
				if (a1 == 0){
					int arm = execl("bash2_2.sh","bash1_1.sh",NULL);
					perror("hi4::");
					sleep(2);
					exit(EXIT_SUCCESS);
				}
				else if (a1 > 0){
					waitpid(a1,NULL,0);
					if (clock_gettime(CLOCK_REALTIME, &end2) == -1){
						perror("hard luck");
					}
					aa2 = (end2.tv_sec - start2.tv_sec) + (double)(end2.tv_nsec - start2.tv_nsec) /(double) BILLION;
					
					if (clock_gettime(CLOCK_REALTIME, &start3) == -1){
						perror("hard luck");
					}
					int p2 = fork();
					if (p2 == 0){
						int arc = execl("bash3.sh","bash3.sh",NULL);
						printf("%d",arc);
						perror("hi5:: ");
						sleep(2);
						exit(EXIT_SUCCESS);
					}
					else if (p2 > 0){
						waitpid(p2,NULL,0);
						int a2 = fork();
						if (a2 == 0){
							int arm = execl("bash3_3.sh","bash1_1.sh",NULL);
							perror("hi2::");
							sleep(2);
							exit(EXIT_SUCCESS);
						}
						else if (a2 > 0){
							waitpid(a2,NULL,0);
							if (clock_gettime(CLOCK_REALTIME, &end3) == -1){
								perror("hard luck");
							}
							aa3 = (end3.tv_sec - start3.tv_sec) + (double)(end3.tv_nsec - start3.tv_nsec) /(double) BILLION;
						}
						
					}
					
				}
				
			}
			
		}
	}
	printf("%lf %lf %lf ",aa1,aa2,aa3);
	return 0;
}
