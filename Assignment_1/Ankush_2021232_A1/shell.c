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
    // printf("%s",root);

    while(1){
        printf("A1>>>");
        fgets(input,size,stdin);
        char rf[100];
        strcpy(rf,root);
        char *final=input;
        // inCmd = 1) exit
        //         2)  cd :- cd, cd ..
        //         3) echo :- echo, echo -n
        //         4) pwd :- pwd, pwd -L
        char * exection[10];
        int count = 0; 
        char * token = strtok(input, " ");
        // loop through the string to extract all other tokens
        while( token != NULL ) {
            exection[count] = token;
            count++;
            token = strtok(NULL, " ");
        }
        // printf("%s",exection[0]);
	    int check  = 0;
        // printf("%s",exection[0]);
        if (strcmp(exection[0],"exit\n") == 0){
            check = 1;
            break;
        }
        else if (exection[0] == NULL){
            break;
        }
        else if (strcmp(exection[0], "cd\n") == 0){
            // printf("cd1");
	        check = 1;
            chdir("/home/ankush"); // {do /home/ankush}
            char add[100];
            getcwd(add,100);
            printf("A1>>>%s\n",add);
        }
        else if (strcmp(exection[0], "cd") == 0 && strcmp(exection[1], "..\n") == 0){
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
        else if(strcmp(exection[0], "cd") == 0 && exection[2] == NULL){
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
            int i=1;
	        check = 1;
            printf("A1>>>");
            while(exection[i+1]!= NULL){
                printf("%s ",exection[i]);
                i++;
            }
            char new[19];
            int k;
            for (k = 0; k < 19; k++){
                if (exection[i][k] == '\n'){
                    break;
                }
                new[k] = exection[i][k];
            }
            new[k] = '\0';
            printf("%s",new);
        }
        else if (strcmp(exection[0], "echo") == 0 && strcmp(exection[1],"--help\n") == 0){
            printf("A1>>>\n");
            printf ("Prints input u gave\n");
            printf("All suported operations are!!!!!\n");
            printf("1) echo NULL --> print new line charachter\n");
            printf("1) echo -n word --> print word without new line charachter\n");
            printf("2) echo --help --> you are seeing what it can do baby\n");
        }
        else if(strcmp(exection[0], "echo") == 0 && exection[1]==NULL){
            printf("A1>>>\n");
	        check = 1;
        }
        else if (strcmp(exection[0], "echo") == 0){
            int i=1;
	        check = 1;
            printf("A1>>>");
            while(exection[i+1]!= NULL){
                printf("%s ",exection[i]);
                i++;
            }
            printf("%s",exection[i]);
        }

        else if (strcmp(exection[0], "pwd\n") == 0){
            // printf("pwd1");
            char add[100];
	        check = 1;
            getcwd(add,100);
            printf("A1>>>%s\n",add);
        }
        else if (strcmp(exection[0], "pwd") == 0 && (strcmp(exection[1], "-L\n") == 0 || strcmp(exection[1], "-P\n") == 0)){
            // printf("pwd2");
            char add[100];
	        check = 1;
            getcwd(add,100);
            printf("A1>>>%s\n",add);
        }

        if (strcmp(exection[0] , "&T") == 0){
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, myThreadFun, NULL);
            char a[100];
            int ip = 1;
            while(exection[ip] != NULL){
                strcat(a,exection[ip]);
                strcat(a," ");
                ip++;
            }
            system(a);
            pthread_join(thread_id, NULL);
        }
        else{
            int fork1 = fork();
            if (fork1 == 0){
                if (strcmp(exection[0],"ls\n") == 0){
                    check = 1;
                    strcat(rf,"/ls");
                    execv(rf,exection);	
                }
                else if (strcmp(exection[0],"ls") == 0 && (strcmp(exection[1],"-R\n") == 0 || strcmp(exection[1],"-m\n") == 0 )){
                    check = 1;
                    strcat(rf,"/ls");
                    execv(rf,exection);
                }
                else if (strcmp(exection[0],"cat") == 0 && (exection[2] == NULL || strcmp(exection[1],"-n") == 0  || strcmp(exection[1],"-E") == 0)){
                    check = 1;
                    strcat(rf,"/cat");
                    execv(rf,exection);
                    
                }
                else if (strcmp(exection[0],"date") == 0 && (strcmp(exection[1],"-I\n") == 0 || strcmp(exection[1],"-R\n") == 0)){
                    check = 1;
                    strcat(rf,"/date");
                    execv(rf,exection);
                }
                else if (strcmp(exection[0],"date\n") == 0){
                    check = 1;
                    strcat(rf,"/date");
                    execv(rf,exection);
                }
                else if (strcmp(exection[0],"rm") == 0 && exection[2] == NULL){
                    check = 1;
                    strcat(rf,"/rm");
                    execv(rf,exection);
                }
                else if (strcmp(exection[0],"rm") == 0 && (strcmp(exection[1],"-i") == 0 || strcmp(exection[1],"-f") == 0)){
                    check = 1;
                    strcat(rf,"/rm");
                    execv(rf,exection);
                }
                else if (strcmp(exection[0],"mkdir") == 0 && (strcmp(exection[1],"-v") == 0 || strcmp(exection[1],"-p") == 0)){
                    check = 1;
                    strcat(rf,"/mkdir");
                    execv(rf,exection);
                }
                else if (strcmp(exection[0],"mkdir") == 0 && exection[2] == NULL){
                    check = 1;
                    strcat(rf,"/mkdir");
                    execv(rf,exection);
                }
                else{
                    if (check  == 0){
                        printf("A1>>> Command not found\n");
                    }
                }
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
    }
    return 0;
}
