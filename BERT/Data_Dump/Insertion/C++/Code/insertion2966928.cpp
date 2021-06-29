#include <iostream>

using namespace std;

void insertionSort(int* A, int N)
{
	for (int k = 0; k < N; k++)
	{
		if (k != 0) cout << " ";
		cout<< A[k];
	}

	cout << endl;

	for (int i = 1; i < N; i++)
	{
		int v = A[i];
		int j = i - 1;
		
		while (j >= 0 && A[j] > v)
		{
			A[j + 1] = A[j];

			j--;
		}

		A[j + 1] = v;

		for (int k = 0; k < N; k++)
		{
			if (k != 0) cout << " ";
			cout << A[k];
		}

		cout << endl;
	}
}

int main() 
{
	int N;
	int A[100];

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	insertionSort(A, N);
	/*
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;
	*/
	return 0;
}
