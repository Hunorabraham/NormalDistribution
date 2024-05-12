#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_ITERATION 1000
#define LINE_WIDTH 30;

void moveTo(int, int);
void safeGets(char[], int);
int parseInt(char[],int);
void printlines(int[]);
//fgets is broken, crashes program if too many(n-1) chars are passed, endl(\n) included, I'll be using scanf and getchar
//scanf is even more broken just straight up crashing the program no matter what
//memory leak????

union extFloat{
	float value;
	int intbits : 1;
};

int main(){
	system("exit");
	int throws[11];
	for(int i = 0; i < 11 ; i++){
		throws[i] = 0;
	}
	int index;
	for(int i = 0; i < MAX_ITERATION; i++){
		index = (rand()%6)+1;
		index += (rand()%6)+1;
		moveTo(throws[index-2]+1,index-1);
		printf("*");
		throws[index-2]++;
		moveTo(1,14);
		//printf("%d   \n",index);
		for(int j = 0; j < 11 ; j++){
			printf("%d\n",throws[j]);
		}
		//Sleep(1);
	}
	printf("\nend of execution, press any button to exit");
    getchar();
	return 0;
}

void moveTo(int x, int y){
	printf("\033[%d;%dH",y,x);
}

/*
void safeGets(char[] destination, int size){
	
};*/

