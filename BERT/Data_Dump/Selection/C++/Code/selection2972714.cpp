#include <iostream>

using namespace std;

int bubbleSort(int* A, int N)
{
	bool flag = 1;
	int count = 0;

	while (flag)
	{
		flag = 0;
		for (int j = N - 1; j > 0; j--)
		{
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				count++;
				flag = 1;
			}
		}
	}

	return count;
}

int selectionSort(int* A, int N)
{
	int count = 0;

	for(int i = 0; i < N; i++)
	{
		int minj = i;
		for (int j = i; j < N; j++)
		{
			if (A[j] < A[minj])
			{
				minj = j;
			}
		}
		if (i != minj)
		{
			swap(A[i], A[minj]);
			++count;
		}
	}

	return count;
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

	int count = selectionSort(A, N);

	for (int i = 0; i < N; i++)
	{
		if (i) cout << " ";
		cout << A[i];
	}

	cout << endl;
	cout << count << endl;

	return 0;
}
