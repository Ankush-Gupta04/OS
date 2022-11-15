HI

#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define BILLION 1000000000L;

void *runner1(void *param){
    long int i = 0;
    long int k = pow(2,32) - 1;
    while (k > i){
        i++;
    }
    pthread_exit(0);
}

void *runner2(void *param){
    int k = 0;
    for (long int i = 0; i < pow(2,32); i++){
        k = 1;
    }
    pthread_exit(0);
}

void *runner3(void *param){
    long int i = 0;
    long int k = pow(2,32) - 1;
    while (k > i){
        i++;
    }
    pthread_exit(0);
}

int main(){
    int i, policy;
    pthread_t ids[3];
    pthread_attr_t type;

    pthread_attr_init(&type);

    if (pthread_attr_getschedpolicy(&type, &policy) != 0){
        fprintf(stderr,"unable to get policy.\n");
    }
    else{
        if (policy == SCHED_OTHER){
            printf("1 ");
        }
        else if (policy == SCHED_RR){
            printf("2 ");
        }
        else if (policy == SCHED_FIFO){
            printf("1 ");
        }
    }



    if (pthread_setschedpolicy(&type, SCHED_FIFO) != 0){
        fprintf(stderr,"unable to set policy.\n");
    }

    struct timespec start, end;
    double samay;

    if (clock_gettime(CLOCK_REALTIME, &start) == -1){
        perror("clock_gettime doesnot work!");
    }

    pthread_create(&ids[0],&type,runner1,NULL);
    pthread_create(&ids[1],&type,runner2,NULL);
    pthread_create(&ids[2],&type,runner3,NULL);
    

    pthread_join(ids[0],NULL);
    pthread_join(ids[1],NULL);
    pthread_join(ids[2],NULL);

    if (clock_gettime(CLOCK_REALTIME, &end) == -1){
        perror("clock_gettime doesnot work!");
    }

    samay = (end.tv_sec - start.tv_sec) + (end.tv_sec - start.tv_sec) / BILLION;

    printf("%lf\n",samay);  

    return 0;
}
