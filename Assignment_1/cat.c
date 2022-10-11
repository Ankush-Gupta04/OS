#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char file1[10];
	char file2[10];
	scanf("%s", file1);
	strcpy(file2,"-n");
	printf("%s ", file1);
	printf("%s \n",file2);
	FILE* temp;
	printf("A1>>>");
	if (strcmp(file2, "-n") == 0){	
		if (file1 != NULL){
			temp = fopen(file1 , "r");
			if (temp == NULL){
				printf("File not found!!");
			}	
			else{
				char c;
				while (c != EOF){
					c = fgetc(temp);
					printf("%c",c);
				}
			}
			fclose(temp);
		}
	}
//	if (file2 != NULL){
//		temp1 = fopen(file2, "r");
//		if (temp1 == NULL){
//			printf("File not found!!");
//		}
//		else{
//			char cd;
//			while (cd!= EOF){
//				cd = fgetc(temp1);
//				printf("1");
//				printf("%c",temp1);
//			}
//		}
//		fclose(temp1);
//	}
	return 0;
	//FILE* ptr;
}
