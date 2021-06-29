// AOJ
// ALDS1_1_A Insertion Sort

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, i, j, v, k;
	cin >> N;
	int A[N];
	for (i=0; i<N; i++) {
		cin >> A[i];
	}

	for (i=0; i<N; i++) {
		cout << A[i];
		if (i!=N-1) {
			cout << " ";
		}
	}
	cout << endl;

	for (i=1; i<N; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		for(k=0; k<N; k++) {
			cout << A[k];
			if (k!=N-1) {
				cout << " ";
			}
		}
		cout << endl;
	}
}

