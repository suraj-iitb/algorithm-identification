#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

#include <stdio.h>

void print(int A[], int N){
	rep(i, N){
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

void insertionSort(int A[], int N){
	int v;

	FOR(i, 1, N){
		v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		print(A, N);
	}
}

int main() {

	int N;
	cin >> N;

	const int MAX_N = 10000;
	int A[MAX_N];
	rep(i, N){
		cin >> A[i];
	}
	print(A, N);
	insertionSort(A, N);

	return 0;
}
