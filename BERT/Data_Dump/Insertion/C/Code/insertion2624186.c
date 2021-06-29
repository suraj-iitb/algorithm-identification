#include <stdio.h>
#define N 100

void printA(int *A,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",A[i]);
		if(i!=n-1)printf(" ");
		else printf("\n");
	}
}

void insertionSort(int *A,int n){
	int i,v,j;
	printA(A,n);
	for(i=1;i<n;i++){
		v = A[i];
		j = i-1;
		while(j>=0 && A[j]>v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		printA(A,n);
	}
}

int main(){
	int n;
	int i;
	int A[N];

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}

	insertionSort(A,n);

	return 0;
}
