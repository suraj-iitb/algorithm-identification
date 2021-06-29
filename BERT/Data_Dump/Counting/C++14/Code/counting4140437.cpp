#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
constexpr auto INF = 2147483647;
constexpr auto MAX = 2000001;
constexpr auto VMAX = 10001;
typedef long long ll;

int A[MAX], B[MAX], C[VMAX];

void CountingSort(int n) {
	rep(i, VMAX) C[i] = 0;
	rep(i, n) C[A[i]]++;
	for (int i = 1; i < VMAX; i++) C[i] = C[i] + C[i - 1];
	for (int i = n; i >= 0; i--) {
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
}

int main() {
	int n;
	cin >> n;
	rep(i, n) cin >> A[i];
	
	CountingSort(n);
	rep(i, n) {
		if (i) cout << " ";
		cout << B[i];
	}
	cout << endl;

	return 0;
}
