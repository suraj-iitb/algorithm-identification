#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define INF 1000000001

using namespace std;

int nos;

void merge(vector<int>& A, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	vector<int> L(n1+1);
	vector<int> R(n2+1);
	for (int i = 0; i < n1; ++i) {
		L[i] = A[left+i];
	}
	L[n1] = INF;
	for (int i = 0; i < n2; ++i) {
		R[i] = A[mid+i];
	}
	R[n2] = INF;

	int lind = 0;
	int rind = 0;
	for (int i = left; i < right; ++i) {
		if (L[lind] < R[rind]) {
			A[i] = L[lind];
			++lind;
		}
		else {
			A[i] = R[rind];
			++rind;
		}
		++nos;
	}
	return;
}

void merge_sort(vector<int>& S, int left, int right) {
	if (left+1 < right) {
		int mid = (left+right)/2;
		merge_sort(S,left,mid);
		merge_sort(S,mid,right);
		merge(S,left,mid,right);
	}
	return;
}

int main(void) {
	int n;
	cin >> n;
	vector<int> S(n);
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
	}
	nos = 0;
	merge_sort(S,0,n);
	for (int i = 0; i < n; ++i) {
		cout << S[i];
		if (i < n-1) {
			cout << " ";
		}
	}
	cout << endl;
	cout << nos << endl;
	return 0;
}

