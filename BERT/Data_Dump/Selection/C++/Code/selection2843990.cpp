#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long ll;
const int MAXN = 100;

int selectionsort(int *A, int N) {
	int  count = 0;
	for (int i = 0; i < N - 1; i++) {
		int minj = i;
		for (int j = i + 1; j < N; j++) {
			if (A[minj] > A[j])minj = j;
		}
		if (minj != i) {
			swap(A[minj], A[i]);
			count++;
		}
	}
	return count;
}

int main() {
	int  N, count;
	int A[MAXN];
	cin >> N;
	rep(i, N)cin >> A[i];
	count = selectionsort(A, N);
	rep(i, N) {
		if (i != N - 1)cout << A[i] << " ";
		else cout << A[i] << endl;
	}
	cout << count << endl;
	return 0;
}
