#include <bits/stdc++.h>
using namespace std;

void print_array(int *A, int N)
{
	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i != N - 1)
			cout << " ";
	}
	cout << endl;
}

void insertion_sort(int *A, int N)
{
	print_array(A, N);
	for (int i = 1; i < N; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		print_array(A, N);
	}
}

int main()
{
	int N, A[100];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	insertion_sort(A, N);
}

