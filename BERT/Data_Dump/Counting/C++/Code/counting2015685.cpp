#include<iostream>
#include<climits>
using namespace std;
void CountingSort(int[], int,int);

int main() {
	int n;
	int A[2000001];
	int k;
	cin >> n;
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (max < A[i]) max = A[i];
	}
	k = max;
	CountingSort(A, k, n);
	for (int i = 0; i < n; i++) {
		cout << A[i];
		if (i != n - 1) cout << " ";
		else cout << endl;
	}
}

void CountingSort(int A[], int k,int n) {
	int C[10001], B[2000001];
	for (int i = 0; i <= k; i++) {
		C[i] = 0;
	}
	for (int j = 0; j < n; j++) {
		C[A[j]]++;
	}
	for (int i = 1; i <= k; i++) {
		C[i] = C[i] + C[i - 1];
	}
	for (int j = n - 1; j >= 0; j--) {
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;
	}
	for (int i = 0; i < n; i++) {
		A[i] = B[i];
	}

}
