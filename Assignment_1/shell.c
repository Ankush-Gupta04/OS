#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h> 

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
        char * exection[4];
        int count = 0; 
        char * token = strtok(input, " ");
        // loop through the string to extract all other tokens
        while( token != NULL ) {
            exection[count] = token;
            count++;
            token = strtok(NULL, " ");
        }
        // printf("%s",exection[0]);
        if (strcmp(exection[0], "exit\n") == 0){
            break;
        }
        else if (exection[0] == NULL){
            break;
        }
        else if (strcmp(exection[0], "cd\n") == 0){
            // printf("cd1");
            chdir("/home/iiitd"); // {do /home/ankush}
            char add[100];
            getcwd(add,100);
            printf("A1>>>%s\n",add);
        }
        else if (strcmp(exection[0], "cd") == 0 && strcmp(exection[1], "..\n") == 0){
            // printf("cd2");

            chdir("..");
            char add[100];
            getcwd(add,100);
            printf("A1>>>%s\n",add);
        }
        else if (strcmp(exection[0], "echo") == 0 && strcmp(exection[1], "-n") == 0){
            // printf("echo2");
            printf("c\n");
            int k = 0;
            for (int i = 2; i < 4; i++){
                if (exection[i] == NULL){
                    k = i;
                    break;
                }
            }
            printf("A1>>>");
            for (int i = 2; i < k; i++){
                printf("%s ",exection[i]);
            }
            printf("%s",exection[k]);

        }
        else if (strcmp(exection[0], "echo") == 0){
            // printf("echo1");
            int k = 0;
            for (int i = 1; i < 4; i++){
                if (exection[i] == NULL){
                    k = i;
                    break;
                }
            }
            printf("A1>>>");
            for (int i = 1; i < k; i++){
                printf("%s ",exection[i]);
            }
            printf("%s\n",exection[k]);
        }
        else if (strcmp(exection[0], "pwd\n") == 0){
            // printf("pwd1");
            char add[100];
            getcwd(add,100);
            printf("A1>>>%s\n",add);
        }
        else if (strcmp(exection[0], "pwd") == 0 && strcmp(exection[1], "-L\n") == 0){
            // printf("pwd2");
            char add[100];
            getcwd(add,100);
            printf("A1>>>%s\n",add);
        }
    }
}