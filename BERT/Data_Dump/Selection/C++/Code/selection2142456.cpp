#include <iostream>
using namespace std;

int main()
{
	int N,minj,change,count;
	int A[100];
	count = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N-1; ++i)
	{
		minj = i;
		for (int j = i; j < N; ++j)
		{
			if (A[j] < A[minj])
			{
				minj = j;
			}
		}
		if (minj != i)
		{			
			change = A[i];
			A[i] = A[minj];
			A[minj] = change;
			count += 1;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (i != N-1)
		{
			cout << A[i] << " ";
		}
		else
		{
			cout << A[i] << "\n";
		}
	}
	cout << count << "\n";
	return 0;
}
