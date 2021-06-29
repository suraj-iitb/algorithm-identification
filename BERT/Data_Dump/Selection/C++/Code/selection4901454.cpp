#include<iostream>
using namespace std;

void trace(int A[], int N) {
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << A[i];
	}
	cout << endl;
}

int selectionSort(int A[], int N) {
	int i,j,sw,minj;
	sw = 0;
	for (i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++)
		{
			if (A[j] < A[minj])
			{
				minj = j; 

			}
		}
		if (A[i] != A[minj]) { 
			swap(A[i], A[minj]); sw++; 
		}
					
	}

	return sw;

}

int main() {
	int A[100], i, N,sw; cin >> N;
		for (i = 0; i < N; i++) cin >> A[i];
		sw = selectionSort(A,N);
		trace(A, N);
		cout << sw << endl;
}
