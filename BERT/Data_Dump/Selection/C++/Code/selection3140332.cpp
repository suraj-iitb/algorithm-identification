#include<iostream>
#include<cstdio>
#include<math.h>
#define N 100
using namespace std;
int main()
{
	int n, total = 0;
	int A[N];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < n; i++)
	{
		int mini = A[i];
		int minnum = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < mini)
			{
				mini = A[j];
				minnum = j;
			}
		}
		if (minnum != i)
		{
			swap(A[minnum], A[i]);
			total++;
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
