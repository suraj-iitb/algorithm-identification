#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define Max 1000

int main()
{
	int N;
	cin >> N;
	int A[Max];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int s = 0; s < N; s++)
	{
		cout << A[s];
		if (s < N-1)
			cout << ' ';
	}
	cout << endl;
	for (int i = 1; i < N; i++)
	{
		int tmp = A[i];
		int j = i - 1;
		for (j; j >= 0; j--)
		{
			if (tmp < A[j])
			{
				swap(A[j], A[j + 1]);
			}
			else
				break;
		}
		A[j + 1] = tmp;
		for (int s = 0; s < N; s++)
		{
			cout << A[s];
			if (s < N-1)
				cout << ' ';
		}
		cout << endl;
	}
	return 0;
}

