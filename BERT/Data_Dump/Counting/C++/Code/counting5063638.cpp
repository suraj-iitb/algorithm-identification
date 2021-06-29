#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=2000000;
const int MAX_I=10000;
int A[MAX_N+1], B[MAX_N+1], C[MAX_I+1];

void Counting_sort(int A[], int B[], int n) {

	for (int i=0; i<=MAX_I; i++) C[i]=0;

	for (int i=1; i<=n; i++) C[A[i]]++;

	for (int i=1; i<=MAX_I; i++) C[i] += C[i-1];

	for (int i=1; i<=n; i++) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}

int main() {

	int n;
	
	cin >> n;
	for (int i=1; i<=n; i++) cin >> A[i];

	Counting_sort(A, B, n);

	for (int i=1; i<=n; i++) {
		if (i!=1) cout << ' ';
		cout << B[i];
	}
	cout << endl;

	return 0;
}
 
