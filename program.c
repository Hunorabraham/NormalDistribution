#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_ITERATION 1000

void moveTo(int, int);
void safeGets(char[], int);
int parseInt(char[],int);
void throwDice(int);
void printlines(int[]);
//fgets is broken, crashes program if too many(n-1) chars are passed, endl(\n) included, I'll be using scanf and getchar
//scanf is even more broken just straight up crashing the program no matter what. so fgets it is
//memory leak????

union extFloat{
	float value;
	int intbits : 1;
};

int main(){
	system("exit");
	printf("\nhow many throws[2-5]?: ");
	char howmany[10];
	fgets(howmany, 10, stdin);
	printf("\necho: %d", (int)howmany[0]-48);
	int amount = (int)howmany[0]-48;
	if(amount<2){
		amount = 2;
	}
	throwDice(amount);
	printf("\nend of execution, press any button to exit");
    getchar();
	return 0;
}

void moveTo(int x, int y){
	printf("\033[%d;%dH",y,x);
}

void throwDice(int n){
	int possibilities = (n*6)-n+1;
	int throws[possibilities];
	int index = 0;
	for(int i = 0; i < possibilities ; i++){
		throws[i] = 0;
	}
	for(int i = 0; i < MAX_ITERATION; i++){
		index = 0;
		for(int j = 0; j < n; j++){
			index += (rand()%6)+1;
		}
		moveTo(throws[index-n]+1,index-n+1);
		printf("*");
		throws[index-n]++;
		moveTo(1,possibilities+2);
		//printf("%d   \n",index);
		for(int j = 0; j < possibilities; j++){
			printf("%d: %d\n",j+n, throws[j]);
		}
	}
}