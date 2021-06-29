#include<iostream>
#include<math.h>
#define N 100

using namespace std;
int main()
{
	int n;
	int total = 0;
	int A[N];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			if (A[j] < A[j - 1])
			{
				swap(A[j], A[j - 1]);
				total++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << A[i];
		if (i < n - 1)
			cout << ' ';
	}
	cout << endl;
	cout << total << endl;
	return 0;
}
