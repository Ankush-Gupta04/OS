#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>


void *myThreadFun(void *vargp){
    sleep(1);
    return NULL;
}

int main(){
    int size = 1000;
    char input[size];
    char root[100];
    getcwd(root,100);

    while(1){
        printf("A1>>>");
        fgets(input,size,stdin);
        char rf[1000];
        strcpy(rf,root);
        char *final=input;
        char *exection[10];
        int i = 0;
        int j = 0;
        int k = 0;
        while(input[i] != '\0'){
            char * d = (char *)malloc(sizeof(char) * 10);
            while(1){
                if (input[i] == ' '){
                    d[k] = '\0';
                    exection[j] = d;
                    k = 0;
                    j++;
                    i++;
                    break;
                }
                else if(input[i] == '\n'){
                    d[k] = '\0';
                    exection[j] = d;
                    k = 0;
                    j++;
                    i++;
                    break;
                }
                else{
                    d[k] = input[i];
                    i++;
                    k++;
                }
            }            
        }
        exection[j] = NULL;

	    int check  = 0;
        if (strcmp(exection[0],"exit") == 0){
            check = 1;
            break;
        }
        else if (exection[0] == NULL){
            break;
        }
        else if (strcmp(exection[0], "cd") == 0 && strcmp(exection[1], "..") == 0){
            // printf("cd2");
	        check = 1;
            chdir("..");
            char add[100];
            getcwd(add,100);
            printf("A1>>>%s\n",add);
        }
        else if (strcmp(exection[0], "cd") == 0 && (strcmp(exection[1],"-P") == 0 || strcmp(exection[1],"-L") == 0)){
            check = 1;
            char filename[19];
            int  i;
            for (i = 0; i < 19; i++){
                if (exection[2][i] == '\n'){
                    break;
                }
                if (exection[2][i] == '\0'){
                    break;
                }
                filename[i] = exection[2][i];
            }
            filename[i] = '\0';
            int k = chdir(filename);
            if (k == 0){
                char add[100];
                getcwd(add,100);
                printf("A1>>>%s\n",add);
            }
            else{
                printf("A1>>> Directory doesnot exist\n");
            }
        }
        else if(strcmp(exection[0], "cd") == 0){
            // printf("hi\n");
            check = 1;
            char filename[19];
            int  i;
            for (i = 0; i < 19; i++){
                if (exection[1][i] == '\n'){
                    break;
                }
                if (exection[1][i] == '\0'){
                    break;
                }
                filename[i] = exection[1][i];
            }
            filename[i] = '\0';
            int k = chdir(filename);
            if (k == 0){
                char add[100];
                getcwd(add,100);
                printf("A1>>>%s\n",add);
            }
            else{
                printf("A1>>> Directory doesnot exist\n");
            }
        }
        else if (strcmp(exection[0], "echo") == 0 && strcmp(exection[1],"-n") == 0){
            check = 1;
            char * c = strtok(exection[2],"\n");
            printf("A1>>>%s",c);
        }
        else if (strcmp(exection[0], "echo") == 0 && strcmp(exection[1],"--help") == 0){
            printf("A1>>>\n");
            printf ("Prints input u gave\n");
            printf("All suported operations are!!!!!\n");
            printf("1) echo NULL --> print new line charachter\n");
            printf("1) echo -n word --> print word without new line charachter\n");
            printf("2) echo --help --> you are seeing what it can do baby\n");
        }
        else if (strcmp(exection[0], "echo") == 0){
            int i=1;
	        check = 1;
            printf("A1>>>%s",exection[1]);
        }

        else if (strcmp(exection[0], "pwd") == 0){
            // printf("pwd1");
            char add[100];
	        check = 1;
            getcwd(add,100);
            printf("A1>>>%s\n",add);
        }
        else if (strcmp(exection[0], "pwd") == 0 && (strcmp(exection[1], "-L") == 0 || strcmp(exection[1], "-P") == 0)){
            // printf("pwd2");
            char add[100];
	        check = 1;
            getcwd(add,100);
            printf("A1>>>%s\n",add);
        }
        else if (strcmp(exection[0],"ls") == 0){
            check = 1;
            if (fork() == 0){
                strcat(rf,"/ls");
                printf("%d",check);
                char ans[100] ;
                strcpy(ans,"ls");
                execv(rf,exection);	
                // printf("hi");
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
        else if (strcmp(exection[0],"ls") == 0 && (strcmp(exection[1],"-R") == 0 || strcmp(exection[1],"-m") == 0 )){
            check = 1;
            if (fork() ==0){
                strcat(rf,"/ls");
                execv(rf,exection);
                exit(0);
            }
            else{
                wait(NULL);
            } 
        }
        else if (strcmp(exection[0],"cat") == 0 && (strcmp(exection[1],"-n") == 0  || strcmp(exection[1],"-E") == 0)){
            check = 1;
            if (fork() == 0){
                strcat(rf,"/cat");
                execv(rf,exection);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
        else if (strcmp(exection[0],"cat") == 0){
            check = 1;
            if (fork() == 0){
                strcat(rf,"/cat");
                execv(rf,exection);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
        else if (strcmp(exection[0],"date") == 0 && (strcmp(exection[1],"-I") == 0 || strcmp(exection[1],"-R") == 0)){
            check = 1;
            if (fork() == 0){
                strcat(rf,"/date");
                execv(rf,exection);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
        else if (strcmp(exection[0],"date") == 0){
            check = 1;
            if (fork() == 0){
                strcat(rf,"/date");
                execv(rf,exection);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
        else if (strcmp(exection[0],"rm") == 0 && (strcmp(exection[1],"-i") == 0 || strcmp(exection[1],"-f") == 0)){
            check = 1;
            if (fork() == 0){
                strcat(rf,"/rm");
                execv(rf,exection);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
        else if (strcmp(exection[0],"rm") == 0){
            check = 1;
            if (fork() == 0){
                strcat(rf,"/rm");
                execv(rf,exection);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
        else if (strcmp(exection[0],"mkdir") == 0 && (strcmp(exection[1],"-v") == 0 || strcmp(exection[1],"-p") == 0)){
            check = 1;
            if (fork() == 0){
                strcat(rf,"/mkdir");
                execv(rf,exection);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
        else if (strcmp(exection[0],"mkdir") == 0 && exection[2] == NULL){
            check = 1;
            if (fork() == 0){
                strcat(rf,"/mkdir");
                execv(rf,exection);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
        else if (strcmp(exection[0] , "&T") == 0){
            check = 1;
            pthread_t thread_id;
            char ankush[100];
            int i = 3;
            int j = 0;
            while(input[i] != '\0'){
                ankush[j] = input[i];
                i++;
                j++;
            }            
            pthread_create(&thread_id, NULL, myThreadFun, NULL);
            printf("A1>>>");
            system(ankush);
            pthread_join(thread_id, NULL);
        }
        if (check  == 0){
            printf("A1>>> Command not found\n");
        }
    }
    return 0;
}