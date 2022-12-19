# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define str_len 5

int main(){
    int fd;
    int index = -1;
    char * fifo = "fifo";
    mkfifo(fifo,0666);
    // fd = open(fifo,O_WRONLY);
    // if (fd == -1){
    //     printf("%d",fd);
    //     perror("/n");
    // }
	// int check = write(fd,&index,sizeof(int));
    // if (check == -1){
    //     printf("%d",check);
    //     perror("/n");
    // }
	// close(fd);
    while (index != 49){
        fd = open(fifo,O_RDONLY); // -1
        for (int i = 0 ; i < 5; i ++){
            char *a = malloc(sizeof(char)*4);
            read(fd,a,4); // -1
            printf("%d %s\n",index+i+1,a);
        }
        close(fd);
        index += 5; 
        fd = open(fifo,O_WRONLY);
	    write(fd,&index,sizeof(int));
	    close(fd);
    }
    

    return 0;
}
