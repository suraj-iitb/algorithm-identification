#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

int bubbleSort(vector<int> &A) {
	int ret = 0;
	int n = A.size();
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (A[j - 1] > A[j])
				swap(A[j - 1], A[j]), ret++;
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> v(N); rep(i, 0, N) {
		cin >> v[i];
	}
	int r = bubbleSort(v);
	cout << v[0]; rep(i, 1, v.size()) { cout << " " << v[i]; } cout << endl;
	cout << r << endl;
	return 0;
}
