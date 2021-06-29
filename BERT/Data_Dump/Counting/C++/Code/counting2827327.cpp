/*
 * ALDS1_6_A.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: 13743
 */

#include<cstdio>

int main() {
	int n;
	int A[2000001];
	int B[2000001];
	int C[10001] = {0};

	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &A[i]);
		C[A[i]]++;
	}

	for(int i=0; i<10000; i++) {
		C[i+1] += C[i];
	}

	for(int i=1; i<=n; i++) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}

	printf("%d", B[1]);
	for(int i=2; i<=n; i++) {
		printf(" %d", B[i]);
	}
	printf("\n");
}



