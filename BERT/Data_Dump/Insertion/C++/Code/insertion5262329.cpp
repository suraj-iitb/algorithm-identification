#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void insertionSort(int N, int* A){
	for(int i = 0; i < N; i++){
		printf("%d", A[i]);
		if(i == N-1) printf("\n");
		else printf(" ");
	}
	for(int i = 1; i < N; i++){
		int target = A[i];
		int comp = i - 1;
		while(comp >= 0 && target < A[comp]){
			A[comp + 1] = A[comp];
			--comp;
		}
		A[comp+1] = target;
		for(int i = 0; i < N; i++){
			printf("%d", A[i]);
			if(i == N-1) printf("\n");
			else printf(" ");
		}
	}
}

int main(){
	int N; cin >> N;
	int* A = (int*)calloc(N, sizeof(int));
	for(int i = 0; i < N; i++) cin >> A[i];
	
	insertionSort(N, A);
	
	return 0;
}
