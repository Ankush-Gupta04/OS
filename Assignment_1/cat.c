#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int agrc , char a[], char b[]){
	char file1[10];
	char file2[10];
	strcpy(file2,b);
	int  i
	for (i = 0; i < 10; i++){
		if (a[i] == '\n'){
			break;
		}
		if (a[i] == '\0'){
			break;
		}
		file1[i] = a[i];
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
					if ((int)c == -1){
					}
					else{
						printf("%c", c);
						if (c == '\n'){
							count++;
							printf("%d) " , count);	
						}
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
					if ((int)c == -1){
					}
					else{
						printf("%c", c);
					}
				}
			}
			fclose(temp);
	}
	return 0;
	//FILE* ptr;
}
}
