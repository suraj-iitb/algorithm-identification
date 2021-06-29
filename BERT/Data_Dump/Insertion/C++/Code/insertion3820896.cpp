#include <iostream>
using namespace std;

void trace(int A[], int n) {
	for (int i = 0; i < n; i++) {
		if (i != n - 1){
			cout << A[i] << " ";
		}
		else {
			cout << A[i] << endl;
		}
	 }
}


int main() {
	int n, A[100];
	cin >> n;

	for (int i = 0; i < n; i++) cin >> A[i];
	trace(A, n);

	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int v = A[i];

		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, n);
		
	}
 
 
}

