#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char input[100];
    fgets(input,100,stdin);
    //strcpy(input,"ghj jkjkl j\n");
    //printf("%s",input);
    char *c[10];
    int i = 0;
    int j = 0;
    int k = 0;
    while(input[i] != '\0'){
        char * d = (char *)malloc(sizeof(char) * 10);
        while(1){
            if (input[i] == ' '){
                d[k] = '\0';
                //printf(" %s %d\n",d,j);
                c[j] = d;
                //printf("%s %s\n",c[j],c[0]);
                k = 0;
                j++;
                i++;
                break;
            }
            else if(input[i] == '\n'){
                d[k] = '\0';
                //printf("%d",j);
                c[j] = d;
                //printf("%s %s\n" , c[j],c[0]);
                k = 0;
                j++;
                i++;
                break;
            }
            else{
                // printf("1 %c",input[i]);
                d[k] = input[i];
                i++;
                k++;
            }
        }
        //printf("1 %c",input[i]);
        
    }
    c[j] = NULL;
    // printf("%d\n",j);
    // for (int a = 0; a < j; a++){
    //     printf("%s ",c[2]);
    // }
    // char *d[10];
    execv("rm",c);
    // // // printf("%d",n);   
    // perror("The error is: ");
}