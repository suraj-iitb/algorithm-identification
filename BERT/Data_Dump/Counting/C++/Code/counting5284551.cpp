#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <cstring>
#include <vector>

using namespace std;

#define debug 0
#define rep(i, n) for(int i = 0; i < (int)n; i++)

void countingsort(int* A, int* B, int size, int k){
	int* C = (int*)calloc(k+1, sizeof(int));
	rep(i, size){
		C[A[i]]++;
	}
	for(int i = 1; i < k+1; i++){
		C[i] = C[i] + C[i-1];
	}
	for(int i = size - 1; i >= 0; i--){
		B[C[A[i]]-1] = A[i];
		C[A[i]] -= 1;
	}
}

int main(){
	int n; cin >> n;
	int* A = (int*)calloc(n, sizeof(int));
	int max = 0;
	rep(i,n) {
		cin >> A[i];
		max = (max > A[i])?max:A[i];
	}
	
	
	int* ans = (int*)calloc(n, sizeof(int));
	countingsort(A, ans, n, max);
	
	rep(i, n){
		printf("%d%c", ans[i], " \n"[i == n-1]);
	}
	
	return 0;
}



