
#include<iostream>
using namespace std;

int selectionSort(int A[], int N) {
	int sw = 0;
	for (int i = 0; i < N - 1; i++) {
		int min = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[min]) min = j;
		}
		swap(A[min], A[i]);
		if ( i != min) sw++;
	}
	return sw;
}

int main()
{
	int A[100], N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int sw = selectionSort(A, N);

	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << sw<<endl;
    return 0;
}
