// AOJ
// ALDS1_2_B Selection Sort

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, i, j;
	cin >> N;
	int A[N];
	for (i=0; i<N; i++) {
		cin >> A[i];
	}

	int minj;
	int cnt = 0;
	for (i=0; i<N; i++) { 
		minj = i;
		for (j=i; j<N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		swap(A[i],A[minj]);
		if (i!= minj) cnt++;
	}
	for (i=0; i<N; i++) {
		cout << A[i];
		if (i!=N-1) {
			cout << " ";
		}
	}
	cout << endl;
	cout << cnt << endl;
}
