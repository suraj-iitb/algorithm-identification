#include<iostream>
#include <climits>
#include<vector>
#include<list>
#include<numeric>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int n;

void countingSort(vector<int> A, vector<int> &B, int k) {
	vector<int> C(k, 0);
	REP(i, n) C[A[i]]++;
	FOR(i, 1, k) {
		C[i] += C[i - 1];
	}
	for (int j = n - 1;j >= 0;j--) {
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	vector<int> A(n), B(n);
	REP(i, n) cin >> A[i];
	countingSort(A, B, 10001);
	REP(i, n) {
		if (i < n - 1) cout << B[i] << " ";
		else cout << B[i] << "\n";
	}

	return 0;
}
