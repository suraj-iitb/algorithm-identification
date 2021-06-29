#include<bits/stdc++.h>
using namespace std;

void printA(int A[], int N){
	printf("%d",A[0]);
	for(int i=1; i<N; ++i){
		printf(" %d",A[i]);
	}
	printf("\n");
}

main(){
	int N;
	cin >> N;
	
	int A[N];
	for(int i=0; i<N; ++i){
		cin >> A[i];
	}
	printA(A, N);
	for(int i=1; i<N; ++i){
		int v = A[i];
		int j = i - 1;
		while(j >= 0 && A[j] > v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		
		printA(A, N);
	}
}
