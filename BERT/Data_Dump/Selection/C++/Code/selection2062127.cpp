#include <iostream>

using namespace std;

int selectionSort(int *A, int N) {
	int i, j;
	int minj;
	int sw = 0;
	for (i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (A[j] < A[minj])
				minj = j;
		}
		if(i != minj) {
			swap(A[i], A[minj]);
			sw++;
		}
	}
	return sw;
}

int main(void)
{
	int A[100];
	int N;
    cin>>N;
	int i, sw;
	for(i = 0; i < N; i++) {
		cin>>A[i];
	}
	sw = selectionSort(A, N);
	
	for(i = 0; i< N; i++) {
		if(i > 0) cout<<" ";
		cout<<A[i];
	}
	cout<<endl;
	cout<<sw<<endl;
}
