#include<iostream>
using namespace std;
int main()
{
	int t = 0;
	int n;
	cin >> n;
	int* A = new int[n];



	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[minIndex])
				minIndex = j;
		}
		if (minIndex != i)
		{
			swap(A[i], A[minIndex]);
			t++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
			cout << A[i] << endl;
		else
			cout << A[i] << " ";
	}


	cout << t << endl;












	delete[]A;
	return 0;

}
