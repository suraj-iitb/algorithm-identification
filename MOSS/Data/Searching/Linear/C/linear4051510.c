/*
 ============================================================================
 Name        : alds1_4_a_linearSearch.c
 Author      : lovesaemi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int search(int A[], int n, int key) {
	int i = 0;
	A[n] = key;
	while (A[i] != key) {
		i++;
	}
	return i != n;
}

int main(void) {
	int i, n, A[10000 + 1], q, key, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &key);
		if (search(A, n, key)) {
			sum++;
		}
	}
	printf("%d\n", sum);
	return EXIT_SUCCESS;
}

