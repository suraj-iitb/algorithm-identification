#include <iostream>
#include <algorithm>
using namespace std;

static const int MAX_N=100;

int selection_Sort(int A[], int N){

	int sw=0;

	for (int i=0; i<N-1; i++) {
		int min_j=i;	
		for (int j=i; j<N; j++)
			if (A[j]<A[min_j]) 
				min_j = j;
		if (min_j!=i) {
			swap(A[min_j], A[i]);
			sw++;
		}
	}

	return sw;
}

int main() {

	int N;
	int A[MAX_N]={0};

	cin >> N;
	for (int i=0; i<N; i++) cin >> A[i];

	int sw=selection_Sort(A, N);

	for (int i=0; i<N; i++) {
		if (i>0) cout << ' ';
		cout << A[i];
	}
	cout << endl;

	cout << sw << endl;

	return 0;
}
