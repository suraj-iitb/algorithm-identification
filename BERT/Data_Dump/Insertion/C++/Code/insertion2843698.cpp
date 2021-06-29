#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long ll;
const int MAXN = 100;

int A[MAXN];

int main() {
	int  N;
	cin >> N;
	rep(i, N)cin >> A[i];
	for (int i = 1; i < N; i++) {
		int v = A[i];
		int j = i - 1;
		rep(k, N) {
			cout << A[k];
			if (k != N - 1)cout << " ";
			else cout << endl;
		}
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}
	rep(k, N) {
		cout << A[k];
		if (k != N - 1)cout << " ";
		else cout << endl;
	}
	return 0;
}
