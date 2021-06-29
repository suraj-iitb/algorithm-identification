#include<iostream>
#include<vector>
using namespace std;
const int k = 10001, N = 2000001;

int main() {
	int n;
	cin >> n;
	vector < int > A(N), B(N), C(k, 0);

	for (int i = 1; i <= n; i++) {
		cin >> A[i]; C[A[i]]++;
	}
	
	for (int i = 1; i <= k; i++) {
		C[i] = C[i] + C[i - 1];
	}
	for (int j = n; j >= 1; j--) {
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
	for (int i = 1; i <= n; i++) {
		cout << (i == 1 ? "" : " ") << B[i];
	}
	cout << endl;
	return 0;
}
