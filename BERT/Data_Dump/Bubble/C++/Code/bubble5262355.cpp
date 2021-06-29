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
int bubbleSort(int N, int* A){
	int count = 0;
	bool loop_flg = true;
	while(loop_flg){
		loop_flg = false;
		for(int i = N-1; i > 0; i--){
			if(A[i] < A[i-1]){
				A[i-1] ^= A[i];
				A[i] ^= A[i-1];
				A[i-1] ^= A[i];
				count++;
				loop_flg = true;
			}
		}
	}
	trace(N, A);
	return count;
}

int main(){
	int N; cin >> N;
	int* A = (int*)calloc(N, sizeof(int));
	for(int i = 0; i < N; i++) cin >> A[i];
	
	int ans = bubbleSort(N, A);
	printf("%d\n", ans);
	
	return 0;
}

