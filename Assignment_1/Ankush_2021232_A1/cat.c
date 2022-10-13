#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cat temp.txt
// cat -n temp.txt
// cat -E temp.txt

int main(int agrc , char *c[]){ // char a[] char b[]
	char file1[10];
	char file2[10];
	int index = 2;
	if (c[2] == NULL){
		index = 1;
		strcpy(file2,c[2]);
	}
	else{
		strcpy(file2,c[1]);
	}
	int  i;
	for (i = 0; i < 10; i++){
		if (c[index][i] == '\n'){
			break;
		}
		if (c[index][i] == '\0'){
			break;
		}
		file1[i] = c[index][i];
	}
	file1[i] = '\0';
	FILE* temp;
	printf("A1>>>");
	if (strcmp(file2, "-n") == 0){	
		if (file1 != NULL){
			temp = fopen(file1 , "r");
			if (temp == NULL){
				printf("File not found!!");
			}	
			else{
				int count = 1; 
				char c;
				printf("%d) " , count);
				while (c != EOF){
					c = fgetc(temp);
					if ((int)c == -1){}
					else{
						printf("%c", c);
						if (c == '\n'){
							count++;
							printf("\t%d) " , count);	
						}
					}
				}
			}
			fclose(temp);
		}
	}

	else if (strcmp(file2, "-E") == 0){
		if (file1 != NULL){
			temp = fopen(file1 , "r");
			if (temp == NULL){
				printf("File not found!!");
			}	
			else{
				char c;
				while (c != EOF){
					c = fgetc(temp);
					if ((int)c == -1){}
					else{
						if (c == '\n'){
							printf("%c",'$');	
						}
						printf("%c", c);
					}
				}
			}
			fclose(temp);
		}
	}

	else{
		if (file1 != NULL){
			temp = fopen(file1 , "r");
			if (temp == NULL){
				printf("File not found!!");
			}	
			else{
				char c;
				while (c != EOF){
					c = fgetc(temp);
					if ((int)c == -1){}
					else{
						printf("%c", c);
					}
				}
			}
		}
	}
}