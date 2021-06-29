#include<iostream>
#include<limits>
#define INFINITY 0x7FFFFFFF
void mergeSort(int* A, int left, int right);
using namespace std;
int ct = 0;
int main() {
	int* S;
	int n;
	cin >> n;
	S = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
	}
	/*for (int i = 0; i < n; ++i) {
	cout << S[i];
	cout << " ";
	}
	cout << endl;
	*/
	mergeSort(S, 0, n);

	for (int i = 0; i < n - 1; ++i) {
		cout << S[i];
		cout << " ";
	}
	cout << S[n - 1] << endl;
	cout << ct << endl;

	return 0;

}

void merge(int* A, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	int* L;
	int* R;
	L = new int[n1 + 1];
	R = new int[n2 + 1];
	for (int i = 0; i < n1; ++i) {
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; ++i) {
		R[i] = A[mid + i];
	}
	L[n1] = (int)INFINITY;
	R[n2] = (int)INFINITY;
	int i = 0;
	int j = 0;

	for (int k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
			ct++;
		}
		else {
			A[k] = R[j];
			j = j + 1;
			ct++;
		}
	}
	delete[]L;
	delete[]R;
}

void mergeSort(int* A, int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}
