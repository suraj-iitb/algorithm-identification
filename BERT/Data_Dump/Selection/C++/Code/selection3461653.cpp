#include<iostream>
using namespace std;
static const int N = 100;

int main()
{
	int n, A[N], minj, temp, time;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	time = 0;
	for (int i = 0; i < n; i++)
	{
		minj = i;
		for (int j = i; j < n; j++)
		{
			if (A[j] < A[minj])
				minj = j;
		}

		if (i != minj)
		{
			temp = A[i];
			A[i] = A[minj];
			A[minj] = temp;

			time++;
		}
	}

	for (int i = 0; i < n - 1; i++)
		cout << A[i] << " ";
	cout << A[n - 1] << endl;
	cout << time <<endl;

	return 0;
}
