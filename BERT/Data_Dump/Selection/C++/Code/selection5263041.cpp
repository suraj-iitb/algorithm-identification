#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void trace(int N, int* A){
	for(int i = 0; i < N; i++){
		printf("%d", A[i]);
		if(i == N-1) printf("\n");
		else printf(" ");
	}
}

//昇順
int selectionSort(int N, int* A){
	int count = 0;
	for(int i = 0; i < N; i++){
		int minj = i;
		for(int j = i; j < N; j++){
			minj = (A[minj] <= A[j])?minj:j;
		}
		if(minj != i) count++;
		int t = A[minj];
		A[minj] = A[i];
		A[i] = t;
	}
	trace(N, A);
	return count;
}

int main(){
	int N; cin >> N;
	int* A = (int*)calloc(N, sizeof(int));
	for(int i = 0; i < N; i++) cin >> A[i];
	
	int ans = selectionSort(N, A);
	printf("%d\n", ans);
	
	return 0;
}

