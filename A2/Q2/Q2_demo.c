// Ankush Gupta
// 2021232

#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define SYS_kernel_2d_memcpy 451


int main(int argc, char **argv){
  
    int input[3][3] = { {1,2,3},{1,2,3},{1,2,3}};
    int output[3][3];
 
    printf("Testing custom system call for 2D float matricies  with custom input ");

    long ans = syscall(SYS_kernel_2d_memcpy, (float *)output, (float *)input, 3,3);

    printf("System call returned %ld.\n", ans);
    perror("Reason for error: ");
    if (ans == 0){
    	printf("Output : - After custom system call");

    	for(int i = 0 ; i< 3 ; i++){
	
        	for(int j =0 ; j<3 ; j++){
	
        	    printf("%d ",output[i][j]);
        	}
        	printf("\n");
    	}
  }

  return ans;
}
