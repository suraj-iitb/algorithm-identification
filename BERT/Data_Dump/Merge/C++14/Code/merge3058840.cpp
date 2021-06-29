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

int res = 0;

void merge(vector<int> &A, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	vector<int> L(n1 + 1), R(n2 + 1);
	for (int i = 0;i < n1;i++) L[i] = A[left + i];
	for (int i = 0;i < n2;i++) R[i] = A[mid + i];
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0, j = 0;
	for (int k = left;k < right;k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
		res++;
	}
}

void mergeSort(vector<int> &A, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> S(n);
	REP(i, n) cin >> S[i];
	mergeSort(S, 0, n);
	REP(i, n) {
		if (i < n - 1) cout << S[i] << " ";
		else cout << S[i] << "\n";
	}
	cout << res << "\n";

	return 0;
}
