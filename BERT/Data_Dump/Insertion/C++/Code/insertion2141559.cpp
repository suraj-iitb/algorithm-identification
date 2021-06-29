#include <iostream>
using namespace std;

int main()
{
	int A[100];
	int N,j,v;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
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
	for (int i = 1; i < N; ++i)
	{
		v = A[i];
		j = i-1;
		while((j >= 0)&&(A[j] > v))
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;

		for (int o = 0; o < N; ++o)
		{
			if (o != N-1)
			{
				cout << A[o] << " ";
			}
			else
			{
				cout << A[o] << "\n";
			}
		}

	}
	return 0;
}
