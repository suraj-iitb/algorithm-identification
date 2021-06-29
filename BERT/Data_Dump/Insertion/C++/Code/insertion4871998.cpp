#include <bits/stdc++.h>
using namespace std;

void printArray(int A[], int N){
	for(int i=0; i<N; i++){
		printf("%d", A[i]);
		if(i < N-1) printf(" ");
	}
	printf("\n");
}

void insertationSort(int A[], int N){
	for(int i=1; i<N; i++){
		int buf = A[i];
		int j = i -1;
		while(j >= 0 && A[j] > buf){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = buf;
		printArray(A, N);
	}
}

int main(){
	int N;
	scanf("%d", &N);
	int A[N];
	for(int i=0; i<N; i++) scanf("%d", &A[i]);
    
    printArray(A, N);
	insertationSort(A, N);

	return 0;
}

