#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long ll;
const int MAXN = 100;

int bubblesort(int *A, int N) {
	int flag = 1;
	int count = 0;
	while (flag) {
		flag = 0;
		for (int i = N - 1; i > 0; i--) {
			if (A[i - 1] > A[i]) {
				swap(A[i - 1], A[i]);
				flag = 1;
				count++;
			}
		}
	}
	return count;
}

int main() {
	int  N, count;
	int A[MAXN];
	cin >> N;
	rep(i, N)cin >> A[i];
	count = bubblesort(A, N);
	rep(i, N) {
		if (i != N - 1)cout << A[i] << " ";
		else cout << A[i] << endl;
	}
	cout << count << endl;
	return 0;
}
