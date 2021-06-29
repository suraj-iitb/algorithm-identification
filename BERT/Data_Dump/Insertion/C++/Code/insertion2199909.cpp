#include<iostream>
using namespace std;

int main() {
	int A[100],n;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];

	for (int i=0; i < n; i++) {
		int v = A[i];
		int j = i - 1;
		while ((j >= 0) && (A[j] > v)) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		cout << A[0];
		for (int k = 1; k < n; k++) {
			cout << ' ';
			cout << A[k];
		}
		cout << endl;
	}
	return 0;
}
