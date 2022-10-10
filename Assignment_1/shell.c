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
        else if(strcmp(exection[0], "echo") == 0 && exection[1]==NULL){
            printf("A1>>>\n");
        }
        else if (strcmp(exection[0], "echo") == 0){
            int i=1;
            printf("A1>>>");
            while(exection[i+1]!= NULL){
                printf("%s ",exection[i]);
                i++;
            }
            printf("%s",exection[i]);
            ///
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