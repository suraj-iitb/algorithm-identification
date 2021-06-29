#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include<string>
#include <vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

using namespace std;

int main(){
	int N, A[100], v, j;

	scanf("%d", &N);
	REP(i, N){
		scanf(" %d", &A[i]);
	}

	FOR(i,1, N){

		REP(k, N - 1){
			printf("%d ", A[k]);
		}
		printf("%d\n", A[N - 1]);

		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}

	REP(k, N - 1){
		printf("%d ", A[k]);
	}
	printf("%d\n", A[N - 1]);

	return 0;
}
