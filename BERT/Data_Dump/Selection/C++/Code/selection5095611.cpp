#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX 200000
#define LARGE 2000000000

int main(void) {
	int n=0;
	int A[105] = {0};
	cin >> n;
	rep (i, n) cin >> A[i];

	int cnt=0;
	for (int i; i<n; i++) {
		int v = i;
		for (int j=i; j<n; j++) {
			if (A[v] > A[j]) {
				v = j;
			}
		}
		if (v != i) {
			swap(A[i], A[v]);
			cnt++;
		}
	}

	for (int i=0; i<n; i++) {
		if (i != 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << cnt << endl;

	return 0;
}

