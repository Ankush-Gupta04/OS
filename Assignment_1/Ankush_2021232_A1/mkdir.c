// mkdir -v [directory name] shows msg
// mkdir [directory name] dont show msg
// mkdir: cannot create directory hj: File exist

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

int main(int agrc , char *c[]){ // char a[], char y[]
    char f1[10];
    int index = 2;
    int flag = 0;
    if (c[2] == NULL){
        index = 1;
        strcpy(f1,c[2]);
    }
    else{
        strcpy(f1,c[1]);
    }
    char filename[19];
    int  i;
	for (i = 0; i < 19; i++){
		if (c[index][i] == '\n'){
			break;
		}
		if (c[index][i] == '\0'){
			break;
		}
        if (c[index][i] == '/'){
            flag = i;
        }
		filename[i] = c[2][i];
	}
	filename[i] = '\0';
    
    if (strcmp(f1,"-v") == 0){
        if (flag != 0){
            printf("A1>>> Not possible to create");
        }
        else{
            DIR* dir =opendir(filename);
            if(dir){
                printf("A1>>> Directory %s already exists\n",filename);
                closedir(dir);
            }
            else{
                mkdir((filename), S_IRWXU);
                printf("A1>>> Directory %s has been created \n",filename );
            }
        }
    }

    else if (strcmp(f1,"-p") == 0){
        if (flag == 0){
            DIR* dir =opendir(filename);
            if(dir){
                printf("A1>>> Directory %s already exists\n",filename);
                closedir(dir);
            }
            else{
                mkdir((filename), S_IRWXU);
            }
        }
        else{
            char one[19];
            char two[19];
            int ankush = 0;
            int iiitd = 0;
            for (int i = 0; i < 19; i ++){
                if (iiitd == 1){
                    two[ankush] == filename[i];
                    ankush++;
                }
                else{
                    if (filename[i] == '/'){
                        one[ankush] == '\0';
                        ankush = 0;
                        iiitd = 1;
                    }
                    else{
                        one[ankush] = filename[i];
                        ankush++;
                    }
                }
            }
            two[ankush] = '\0';
            mkdir(one,S_IRWXU);
            chdir(one);
            mkdir(two,S_IRWXU);
            chdir("..");
        }
    }

    else{
        if (flag != 0){
            printf("A1>>> Not possible to create");
        }
        else{
            DIR* dir =opendir(filename);
            if(dir){
                printf("A1>>> Directory %s already exists\n",filename);
                closedir(dir);
            }
            else{
                mkdir((filename), S_IRWXU);
            }
        }
    }
    
    return 0;
}