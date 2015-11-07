#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <setpriolib.h>

int main(void){

	int i;

	i = fork();

	if( i == 0){
		for(;;){
				printf("Filho\n");
		}
	}else{
		setprio(i, 10);
		for(;;){
			printf("Pai\n");
		}
	}

	return 0;
}
