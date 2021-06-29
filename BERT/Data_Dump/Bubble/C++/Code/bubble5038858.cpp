#include <iostream>
#include <algorithm>
using namespace std;

static const int MAX_N=100;

int bubble_Sort(int A[], int N){

	int sw=0;

	for (int i=0; i<N; i++)
	    for (int j=N-1; j>i; j--)
		    if (A[j]<A[j-1]) {
			    swap(A[j], A[j-1]);
				sw++;
			}

	return sw;
}

int main() {

	int N;
	int A[MAX_N]={0};

	cin >> N;
	for (int i=0; i<N; i++) cin >> A[i];

	int sw=bubble_Sort(A, N);

	for (int i=0; i<N; i++) {
		if (i>0) cout << ' ';
		cout << A[i];
	}
	cout << endl;
	
	cout << sw << endl;

	return 0;
}
