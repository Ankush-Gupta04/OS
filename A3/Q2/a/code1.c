# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <time.h>
# include <sys/socket.h>
# include <sys/un.h>

# define str_len 3
# define BILLION 1000000000L;
# define address "Socket.socket"

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

    struct sockaddr_un skt;
    int data_skt;
    if ((data_skt = socket(AF_UNIX,SOCK_SEQPACKET,0)) == -1){
        perror("Creation: ");
        exit(1);
    }

    memset(&skt,0,sizeof(skt));

    skt.sun_family = AF_UNIX;
    strncpy(skt.sun_path,address,strlen(address)+1);
    if (connect(data_skt,(const struct sockaddr *)&skt,sizeof(skt)) == -1){
        perror("Server is down: ");
		exit(1);
    }

    int index = 0;
    while (index != 49){
        if (write(data_skt,list[index],str_len + 1) == -1){
            perror("write1: ");
            exit(1);
        }
        if (write(data_skt,list[index + 1],str_len + 1) == -1){
            perror("write2: ");
            exit(1);
        }
        if (write(data_skt,list[index + 2],str_len + 1) == -1){
            perror("write3: ");
            exit(1);
        }
        if (write(data_skt,list[index + 3],str_len + 1) == -1){
            perror("write4: ");
            exit(1);
        }
        if (write(data_skt,list[index + 4],str_len + 1) == -1){
            perror("write5: ");
            exit(1);
        }

        char buffer[2];
        if (read(data_skt, buffer, sizeof(buffer)) == -1){
            perror("read: ");
            exit(1);
        }
        index = (int)buffer[0];
        printf("%d\n",index);
    }
    close(data_skt);
    return 1;
}
