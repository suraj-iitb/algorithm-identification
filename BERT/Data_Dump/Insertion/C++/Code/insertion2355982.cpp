#include <iostream>
using namespace std;
const int MAX_N = 110;
int i, j, k, v, a[MAX_N], n;
void insertionSort(int A[MAX_N], int N) { // N??????????´??????????0-?????????????????????A
	for (i = 0; i < N-1; ++i) {
		cout << A[i] << " ";
	}
	if(i<N-1)cout<<A[N-1]<<endl;
	if(i==N-1)cout<<A[N-1]<<endl;
	for (i = 1; i < N; i++) {

		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
			A[j + 1] = v;
		}
		for (k = 0; k < N-1; ++k) {
				cout << A[k] << " ";
		}
		if(i<N-1)cout<<A[N-1]<<endl;
		if(i==N-1)cout<<A[N-1]<<endl;
	}


}

int main() {
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> a[i];
	}
	insertionSort(a, n);
	return 0;
}
