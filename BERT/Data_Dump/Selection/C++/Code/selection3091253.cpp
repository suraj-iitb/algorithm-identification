#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *A = new int[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	int count = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		int min = i;
		int j;
		for (j = i; j <= n - 1; j++)
			if (A[j] < A[min])
				min = j;
		if (min != i)
		{
			swap(A[i], A[min]);
			count++;
		}
	}
	for (int i = 0; i < n; i++)
		if (i != n - 1)
			cout << A[i] << " ";
		else
			cout << A[i] << endl;
	cout << count << endl;
	delete[] A;
}
