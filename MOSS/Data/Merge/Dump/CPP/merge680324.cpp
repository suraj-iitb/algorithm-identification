#include <climits>
#include <iostream>
using namespace std;
const int MAX_N = 500000;
int n;
int A[MAX_N];
int count;

void merge(int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1 + 1], R[n2 + 1];
	for (int i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1] = R[n2] = INT_MAX;
	for (int i = 0, j = 0, k = left; k < right; k++) {
		count++;
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
	}
}

void mergeSort(int left, int right){
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid, right);
		merge(left, mid, right);
	}
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	mergeSort(0, n);
	int i = 0; goto FIRST;
	for (; i < n; i++) {
		cout << ' ';
FIRST:
		cout << A[i];
	}
	cout << endl;
	cout << count << endl;
	return 0;
}
