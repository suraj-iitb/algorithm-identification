/* ALDS1_4_A: Linear Search */
/* 20181115 AOJ */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 100001
#define Q 50000

int binarySearch(int *A, int n, int key);

int main(void){
	int n, S[N], q, T[Q], i = 0, j = 0, C = 0;

	scanf("%d", &n);
	while(i < n){
		scanf("%d", &S[i++]);
	}

	scanf("%d", &q);
	i = 0;
	while(i < q){
		scanf("%d", &T[i]);
		if(binarySearch(S, n, T[i++])) C++;
	}

	printf("%d\n", C);

	return 0;
}

int binarySearch(int *A, int n, int key){
	int i = 0, low, high, mid;
	
	low = 0;
	high = n;
	while(low < high){
		mid = (low + high) / 2;
		if(A[mid] == key){
			return 1;
		}else if(A[mid] > key){
			high = mid;
		}else{
			low = mid + 1;
		}
	}

	return 0;
}
