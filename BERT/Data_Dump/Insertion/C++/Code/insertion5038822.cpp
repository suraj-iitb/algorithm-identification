#include <iostream>
#include <algorithm>
using namespace std;

static const int MAX_N=100;


void trace(int A[], int N) {
	for (int i=0; i<N; i++) {
		if (i>0) cout << ' ';
		cout << A[i];
	}
	cout << endl;
}

void insertion_Sort(int A[], int N) {
	
	for (int i=1; i<N; i++) {
		int key=A[i];
		int j=i-1;

		while (j>=0 && A[j]>key) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
		trace(A, N);
	}
}

int main() {

	int N=0;
	int A[MAX_N]={0};

	cin >> N;
	for (int i=0; i<N; i++) cin >> A[i];

	trace(A, N);
	insertion_Sort(A, N);

	return 0;
}
