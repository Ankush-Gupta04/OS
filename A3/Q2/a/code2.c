# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/socket.h>
# include <sys/un.h>
# include <unistd.h>

# define addr "Socket.socket"
# define size 5

int main(){
    struct sockaddr_un name;
    int flag = 0;
    int index = 0;
    char buffer[size];

    int connection_status = socket(AF_UNIX,SOCK_SEQPACKET,0);
    if (connection_status == -1){
        perror("connection: ");
        exit(1);
    }

    memset(&name,0,sizeof(name));
    strncpy(name.sun_path,addr,sizeof(name.sun_path));
    name.sun_family = AF_UNIX;

    if (bind(connection_status,(const struct sockaddr*)&name,sizeof(name)) == -1){
        perror("bind: ");
        exit(1);
    }

    if (listen(connection_status,100) == -1){
        perror("Listen: ");
        exit(1);
    }

    for(;;){
        int data_skt = accept(connection_status,NULL,NULL);
        if (data_skt == -1){
            perror("accept: ");
            exit(1);
        }
        while(1){
            if (read(data_skt,buffer,sizeof(buffer)) == -1){
                perror("read: ");
                exit(1);
            }
            printf("%d ",index);
            for (int i = 0; i < 4; i++){
                printf("%c",buffer[i]);
            }

            printf("\n");
            index++;
            if (index % 5 == 0){
                char a[2] = {(char)index,'\0'};
                if (write(data_skt,a,sizeof(a)) == -1){
                    perror("Write: ");
                    exit(1);
                }
            }
            if (index == 50){
                break;
            }
        }
        close(data_skt);
    }
    return 0;
}
