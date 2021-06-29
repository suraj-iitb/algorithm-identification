#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
constexpr auto INF = 2147483647;
typedef long long ll;

int cnt = 0;
int A[500001];
int L[250002], R[250002];

void Merge(int A[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	rep(i, n1) L[i] = A[left + i];
	rep(i, n2) R[i] = A[mid + i];
	L[n1] = R[n2] = INF;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j]) {
			A[k] = L[i++];
		}
		else{
			A[k] = R[j++];
		}
	}
}

void Mergesort(int A[], int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		Mergesort(A, left, mid);
		Mergesort(A, mid, right);
		Merge(A, left, mid, right);
	}
}

int main() {
	int n;
	cin >> n;
	rep(i, n) cin >> A[i];
	int left = 0;
	int right = n;
	Mergesort(A, left, right);
	rep(i, n) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << cnt << endl;

	return 0;
}
