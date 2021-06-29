// AOJ
// ALDS1_2_A Bibble Sort

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, i, j, v, w, k;
	cin >> N;
	int A[N];
	for (i=0; i<N; i++) {
		cin >> A[i];
	}

	bool flag = 1;
	int cnt = 0;
	for (i=0; flag; i++) { 
		flag = 0;
		for (j=N-1; j>=i+1; j--) {
			if (A[j] < A[j-1]) {
				swap(A[j],A[j-1]);
				cnt++;
				flag = 1;
			}
		}
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
