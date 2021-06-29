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

int BUBBLE_SORT(int A[], int N){

	bool flag = true;
	int c = 0, tmp;

	while (flag){
		flag = false;
		for (int j = N - 1; j >= 1; j--){
			if (A[j] < A[j - 1]){
				tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				c++;
				flag = true;
			}
		}
	}

	return c;
}


int main(){
	int N, A[100], time;
	scanf("%d", &N);
	REP(i, N){
		scanf(" %d", &A[i]);
	}

	time = BUBBLE_SORT(A, N);

	REP(i, N - 1){
		printf("%d ", A[i]);
	}
	printf("%d\n", A[N - 1]);
	printf("%d\n", time);


	return 0;
}



