#include <stdio.h>

void insertionSort(int *, int);
void printArray(int* array, int n);
int main(void){
// Here your code !

	// TODO ?????????????????????????????????????????????
	int input[100];
	int numOfInput;
	int i;

	scanf("%d", &numOfInput);

	for(i = 0; i < numOfInput; i++){
		scanf("%d", &input[i]);
	}
	
	printArray(input, numOfInput);

	insertionSort(input, numOfInput);
	
	return 0;
}

void insertionSort(int* array, int n){
    int i, j, v;
	for(i = 1; i <= n - 1; i++){
		v = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > v){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = v;
		
		printArray(array, n);
	}
}

void printArray(int* array, int n){
    int i;
	for(i = 0; i < n ; i++){
		printf("%d", array[i]);
		if(i < n - 1){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
}
