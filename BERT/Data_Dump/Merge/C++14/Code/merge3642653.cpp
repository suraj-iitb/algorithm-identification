#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


const long INF = 9'999'999'999;

void merge(vector<long>& A, int left, int mid, int right, int& cnt) {
	int lfLen, rtLen;
	lfLen = mid - left;
	rtLen = right - mid;
	vector<long> L(lfLen + 1);
	vector<long> R(rtLen + 1);
	int i, j, k;
	i = j = k = 0;
	for (i = 0;i < lfLen;i++) { L[i] = A[left + i]; }
	for (i = 0;i < rtLen;i++) { R[i] = A[mid + i]; }
	L[lfLen] = INF;
	R[rtLen] = INF;
	i = j = 0;
	for (k = left; k < right; k++)
	{
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		cnt++;
	}
	return;
}

void mergeSort(vector<long>& A, int left, int right, int& cnt) {
	int mid = 0;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid, cnt);
		mergeSort(A, mid, right, cnt);
		merge(A, left, mid, right, cnt);
	}

	return;
}

int main() {


	int n = 0, cnt = 0;
	cin >> n;
	vector<long> A(n);

	for (int i = 0;i < n;i++) { cin >> A[i]; }

	mergeSort(A, 0, n, cnt);

	for (int i = 0;i < n;i++) {
		cout << A[i];
		if (i < n - 1) cout << " ";
	}
	cout << endl;

	cout << cnt << endl;

	return 0;
}

