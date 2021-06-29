#include<stdio.h>

void PRINT(int* A, int N);

int main(void){
	int N,i,v,j;
	
	scanf("%d",&N);
	
	int insertionSort[N];
	for(i=0;i<N;i++){
		scanf("%d",&insertionSort[i]);
	}
	
	PRINT(insertionSort, N);
	
	for(i=1;i<N;i++){
		v = insertionSort[i];
		j=i-1;
		while(j>=0 && insertionSort[j]>v){
			insertionSort[j+1] = insertionSort[j];
			j--;
		}
		insertionSort[j+1] = v;
		PRINT(insertionSort, N);
	}
	return 0;
}

void PRINT(int* A, int N){
	int i;
	printf("%d",A[0]);
	for(i=1;i<N;i++){
		printf(" %d",A[i]);
	}
	printf("\n");
}
