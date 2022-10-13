#include <stdio.h>
#include <string.h>

// rm temp2.txt
// rm -f temp3.txt
// rm -i temp2.txt

int main(int agrc , char *c[]){ // char x[], char y[]
    char f1[10];
    char filename[19];
    int index = 2;
    if (c[2] == NULL){
        strcpy(f1,c[2]);
        index = 1;
    }
    else{
        strcpy(f1,c[1]);
    }
    int  i;
	for (i = 0; i < 19; i++){
		if (c[index][i] == '\n'){
			break;
		}
		if (c[index][i] == '\0'){
			break;
		}
		filename[i] = c[index][i];
	}
	filename[i] = '\0';

    if (strcmp(f1,"-i") == 0){
        printf("A1>>> rm: remove regular empty file %s ?" ,  f1);
        char temp[2];
        scanf("%s",temp);
        if (strcmp(temp,"Y") == 0|| strcmp(temp,"y") == 0){
            int a = remove(filename);
            if (a == 0){
                printf("A1>>> %s removed succesfully",filename);
            }
            else{
                printf("A1>>> rm: cannot remove %s: No such file or directory" , filename);
            }
        }
        else{}
    }

    else if (strcmp(f1,"-f") == 0){
        int a = remove(filename);
        if (a == 0){
            printf("A1>>> %s removed succesfully",filename);
        }
    }

    else{
        int a = remove(filename);
        if (a == 0){
            printf("A1>>> %s removed succesfully",filename);
        }
        else{
            printf("A1>>> rm: cannot remove %s: No such file or directory" , filename);
        }
    }
    return 0;
}