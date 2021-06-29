#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include<cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include<set>
#include<string>
#include <vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

using namespace std;

/*
1 selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 0 から N-1 まで
3     minj = i
4     for j が i から N-1 まで
5       if A[j] < A[minj]
6         minj = j
7     A[i] と A[minj] を交換
*/

int SELECTION_SORT(int A[], int N){
	int c = 0;
	int minj, tmp;
	REP(i, N){
		minj = i;
		FOR(j, i, N){
			if (A[j] < A[minj]){
				minj = j;
			}
		}
		tmp = A[i];
		A[i] = A[minj];
		A[minj] = tmp;
		if (minj != i){
			c++;
		}
	}
	return c;
}

int main(){
	int A[100], N, k;
	scanf("%d", &N);
	REP(i, N){
		scanf(" %d", &A[i]);
	}

	k = SELECTION_SORT(A, N);

	REP(i, N - 1){
		printf("%d ", A[i]);
	}
	printf("%d\n%d\n", A[N - 1], k);


	return 0;
}


