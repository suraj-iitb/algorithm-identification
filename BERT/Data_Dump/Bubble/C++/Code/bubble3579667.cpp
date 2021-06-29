#include<iostream>
#include<stdio.h>
using namespace std;

void trace(int A[],int N){
	for(int i=0;i<N;i++){
		if(i > 0) printf(" ");
		printf("%d",A[i]);
	}
	printf("\n");
}

void bubbleSort(int A[],int N){
	bool flag = 1;
	int sw = 0;
	for(int i=0;flag;i++){
		flag = 0;
		for(int n=N-1;n>i;n--){
			if(A[n-1] > A[n]){
				swap(A[n],A[n-1]);
				flag = 1;
				sw++;
			}
		}
	}
	trace(A,N);
	cout << sw << endl;
}

int main(){
	int N;
	int A[100];
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	bubbleSort(A,N);
	return 0;
}
