#include <iostream>
using namespace std;

void insertionSort(int *A, int N);

int main()
{
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];

	insertionSort(A, N);
	return 0;
}

void insertionSort(int *A, int N)
{
	int v;
	int j;

	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i != N-1)
			cout << ' ';
		else
			cout << '\n';
	}

	for (int i = 1; i <= N-1; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;

		for (int k = 0; k < N; k++) {
			cout << A[k];
			if (k != N-1)
				cout << ' ';
			else
				cout << '\n';
		}

	}


}
