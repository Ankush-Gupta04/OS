#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h> 
#include <dirent.h>


int main(int agrc , char c){
    DIR*p;
    struct dirent *d;
    char buff[100];
    getcwd( buff, 100 );
    p=opendir(buff);
    if(p==NULL){
    perror("Cannot find directory");
    return 0;
    }
    int n = 0;
    char *list[1000];
    while(d=readdir(p)){
        list[n] = d->d_name;
        n++;
    }
    if (c == NULL){ 
        printf("A1>>>");
        for (int i = 0; i < n; i++){
            printf("%s  ", list[i]);
        }
        printf("\n");
    }
    else{
        printf("A1>>>");
        for (int i = n-1 ; i >= 0; i--){
            printf("%s  ", list[i]);
        }
        printf("\n");
    }
    
}