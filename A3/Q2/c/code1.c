# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/types.h>
# include <errno.h>
# include <unistd.h>
# include <time.h>


# define str_len 3
# define BILLION 1000000000L
# define shm_size 27

char** list[50];

char *string_gen() {

    char all[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    char *random = NULL;
    random = malloc(sizeof(char) * (str_len +1));
    if (random){
	    for (int i = 0; i < str_len ; i++) {
                int index = rand() % (int)(sizeof(all) -1);
                random[i] = all[index];
            }

            random[str_len] = '\0';
    }
   // printf("%s",random);
	
    return random;
}

int main(){
	for (int i = 0; i < 50 ; i++){
		list[i] = NULL;
	}
	for (int i = 0 ; i < 50 ; i++){
		char *temp = NULL;
		temp = malloc(sizeof(char)*(str_len+1));
		temp = string_gen();
		list[i] = temp;
	}
	for(int i = 0; i < 50; i++){
		printf("%d %s\n",i,list[i]);
	}
	struct timespec start, end;
	if (clock_gettime(CLOCK_REALTIME, &start) == -1){
		perror("hard luck");
        exit(1);
	}
    char c;
    int smid;
    key_t key;
    char *shm, *s;

    key = 1234;

    smid = shmget(key,shm_size,IPC_CREAT);
    if (smid == -1){
        perror("get: ");
        exit(1);
    }
    if ((shm = shmat(smid,NULL,0)) == (char *) -1){
        perror("attach: ");
        exit(1);
    }

    s = shm;
    int index = 0;
    for (index = 0; index < 5; index++){
        *s ++ = list[index][0];
        *s ++ = list[index][1];
        *s ++ = list[index][2];
        *s ++ = '\0';
        printf("%s\n",s);
    }
    *s = NULL;

    while(*shm != '*')
        sleep(1);
	
if (clock_gettime(CLOCK_REALTIME, &start) == -1){
	perror("hard luck");
exit(1);
}
double aa1 = end.sec-start.sec + (double)(end.n_sec - start.n_sec)/(double)BILLION;
	
    return 0;
}
