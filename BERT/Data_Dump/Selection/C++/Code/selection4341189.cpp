#include <bits/stdc++.h>
using namespace std;

void print_array(int *A, int N)
{
	for (int i = 0; i < N; i++) {
		if (i)
			cout << " ";
		cout << A[i];
	}
	cout << endl;
}

int selection_sort(int *A, int N)
{
	int nswap = 0;
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i + 1; j < N; j++) {
			if (A[minj] > A[j])
				minj = j;
		}
		if (minj != i)
			nswap++;
		swap(A[i], A[minj]);
	}
	return nswap;
}

int main()
{
	int N, A[100];
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int nswap = selection_sort(A, N);
	print_array(A, N);
	cout << nswap << endl;
}

