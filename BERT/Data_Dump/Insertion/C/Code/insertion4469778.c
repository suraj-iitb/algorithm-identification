#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void show(int A[],int n){
	for(int i=0;i<n;i++){
		printf("%d",A[i]);
		if(i==(n-1)){
			printf("\n");
		}else{
			printf(" ");
		}
	}
}

void insertionSort(int A[],int n){
	int tmp;
	int j;
	for(int i=1;i<n;i++){
		show(A,n);
		tmp=A[i];
		j=(i-1);
		while(j>=0 && A[j]>tmp){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=tmp;
		
	}
}

int main(){
    int n;
	int *A;

	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	insertionSort(A,n);
	show(A,n);

	return 0;
}
