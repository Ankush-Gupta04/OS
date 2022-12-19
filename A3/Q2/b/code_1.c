# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <time.h>

# define str_len 3
#define BILLION 1000000000L;

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
	char** list[50];
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
	}
	int fd;
	char * fifo = "fifo";
	mkfifo(fifo,0666);

	int index = -1;

	while(1){
		// fd = open(fifo,O_RDONLY);
		// read(fd,&index,sizeof(int));
		// printf("%d",index);
		// close(fd);

		// if (index == 49){
		// 	break;
		// }
		fd = open(fifo,O_WRONLY);
		// write(fd,index+1,sizeof(int));
		for (int i = 0; i < 5; i++){
			write(fd,list[index + 1 + i],str_len+1);
		}
		close(fd);
		fd = open(fifo,O_RDONLY);
		read(fd,&index,sizeof(int));
		printf("%d\n",index);
		close(fd);

		if (index == 49){
			break;
		}

	}
	if (clock_gettime(CLOCK_REALTIME, &end) == -1){
		perror("hard luck");
	}
	double a1 = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) /(double) BILLION;
	printf("%lf secs\n",a1);
	return 0;
}
