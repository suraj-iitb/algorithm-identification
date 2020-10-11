#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>
void merge(int*, int, int, int,int*);
void mergeSort(int*, int, int,int*);
int main() {
	int *S, n, i,cnt=0;
	scanf("%d", &n);
	S = (int*)calloc(n+1, sizeof(int));
	for (i = 0; i < n; i++)scanf("%d", S + i);
	mergeSort(S, 0, n,&cnt);
	for (i = 0; i < n; i++)printf("%d%c", *(S + i), i < n - 1 ? ' ' : '\n');
	printf("%d\n", cnt);
	free(S);
	return 0;
}

void merge(int *A, int l, int m, int r,int* cnt) {
	int n1 = m - l, n2 = r - m, *L, *R, i, j, k;
	L = (int*)malloc(sizeof(int)*n1+1);
	R = (int*)malloc(sizeof(int)*n2+1);
	for (i = 0; i < n1; i++) *(L + i) = *(A + l + i);
	for (i = 0; i < n2; i++) *(R + i) = *(A + m + i);
	*(L + n1) = 2147483647;
	*(R + n2) = 2147483647;
	for (k = l, i = j = 0; k < r; k++) {
		++*(cnt);
		if (*(L + i) <= *(R + j)) { *(A + k) = *(L + i); ++i; }
		else { *(A + k) = *(R + j); ++j; }
		
	}
	//free(L); free(R);
}

void mergeSort(int *A, int l, int r,int *cnt) {
	int m;
	if (l + 1 < r) {
		m = (l + r) / 2;
		mergeSort(A, l, m,cnt);
		mergeSort(A, m, r,cnt);
		merge(A, l, m, r,cnt);
	}
}
