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

void print(int A[], int N){
	rep(i, N){
		if (i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

void bubbleSort(int A[], int N){
	int count = 0;

	bool flag = true;
	while (flag){
		flag = false;
		for (int i = N - 1; i >= 1; i--){
			if (A[i] < A[i - 1]){
				int temp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = temp;
				flag = true;
				count++;
			}
		}
	}

	print(A, N);
	cout << count << endl;
}

int main() {

	int N;
	cin >> N;

	const int MAX_N = 10000;
	int A[MAX_N];

	rep(i, N){ cin >> A[i]; }

	bubbleSort(A, N);
}
