#include <iostream>
using namespace std;

int main()
{
	int N,flag,change,count;
	int A[100];
	count = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	flag = 1;
	int i = 0;
	while(flag)
	{
		flag = 0;
		for (int j = N-1; j > i ; --j)
		{
			if (A[j] < A[j-1])
			{
				change = A[j];
				A[j] = A[j-1];
				A[j-1] = change;
				flag = 1;
				count += 1;
			}
		}
		++i;
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
