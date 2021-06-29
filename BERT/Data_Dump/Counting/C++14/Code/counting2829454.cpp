#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include<cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include<queue>
#include<set>
#include<string>
#include <vector>

#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define FORL(i,a,b) for(ll i=(a);i<(b);++i)
#define REPL(i,n) FORL(i,0,n)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define RREP(i,n)   RFOR(i,n,0)
using namespace std;

/*
1 CountingSort(A, B, k)
2     for i = 0 to k
3         C[i] = 0
4
5      C[i] に i の出現数を記録する 
6     for j = 1 to n
7         C[A[j]]++
8
9      C[i] に i 以下の数の出現数を記録する
10    for i = 1 to k
11        C[i] = C[i] + C[i - 1]
12
13    for j = n downto 1
14        B[C[A[j]]] = A[j]
15        C[A[j]]--
*/

void CountingSort(int A[], int B[], int k, int n){
	int *C;
	C = new int[k];
	REP(i, k + 1){
		C[i] = 0;
	}
	FOR(i, 1, n + 1){
		C[A[i]]++;
	}
	FOR(i, 1, k + 1){
		C[i] = C[i] + C[i - 1];
	}
	RFOR(j, n, 1){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}

int main(){
	int n, A[2000001], B[2000001], k = 10000;
	scanf("%d", &n);
	FOR(i, 1, n + 1){
		scanf(" %d", &A[i]);
	}

	CountingSort(A, B, k, n);
	FOR(i, 1, n + 1){
		if (i != 1){
			printf(" ");
		}
		printf("%d", B[i]);
	}
	printf("\n");

	return 0;
}
