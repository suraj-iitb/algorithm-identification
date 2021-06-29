#include<iostream>
using namespace std;

int selectionSort(int A[], int N){

	int count = 0;
	for (int i=0; i<N; i++){
		int minj = i;
		for (int j=i; j<N; j++){
			if (A[j] < A[minj]) minj = j;
		}
		swap(A[i], A[minj]);
		if (i != minj) count++;
	}

	for (int i=0; i<N; i++){
		if (i != N-1) cout << A[i] << " ";

		else cout << A[i] << endl;
	}
	cout << count << endl;
}

int main(){
	int A[100], N;

	cin >> N;

	for (int i=0; i<N; i++){
		cin >> A[i];
	}

	selectionSort(A, N);

	return 0;
}
