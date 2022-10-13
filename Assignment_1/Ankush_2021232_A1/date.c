// date -I
// date -R
// date
#include <time.h>
#include <stdio.h>
#include <string.h>

int main(int agrc , char *c[]){
    time_t Time;
	struct tm *tm;
	time(&Time);
	tm=localtime(&Time);
    char ans[1000];
    char f1[10];
    strcpy(f1,c[1]);
    if (strcmp(f1,"-I\n") == 0){
        strftime(ans,1000,"%Y-%m-%d", tm);
	    printf("%s\n", ans);
    }
    else if (strcmp(f1,"-R\n") == 0){
        strftime(ans,1000,"%a, %d %b %Y %X", tm);
	    printf("%s +0530\n", ans);    
    }
    else{
        strftime(ans,1000,"%a, %d %b %Y %X", tm);
	    printf("%s\n", ans);
    }
}