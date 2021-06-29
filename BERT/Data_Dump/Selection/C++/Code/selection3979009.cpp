#include <iostream>
using namespace std;

void selectionSort(int *A, int N);

int main()
{
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];

	selectionSort(A,N);
	return 0;
}

void selectionSort(int *A, int N)
{
	int count = 0;
	int min;

	for (int i = 0; i <= N-1; i++) {
		min = i;

		for (int j = i; j <= N-1; j++) {
			if (A[j] < A[min]) {
				min = j;
			}
		}
		if (min != i) {
			swap(A[i],A[min]);
			count++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i != N-1)
			cout << ' ';
		else
			cout << '\n';
	}

	cout << count << '\n';

	return;
}
