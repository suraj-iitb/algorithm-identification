#include <iostream>
using namespace std;

const int MAX = 100;

int main()
{
	int n, temp, j;
	int A[100];

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	if(n == 1)
	{
		cout << A[0] << endl;
		return 0;
	}

	for(int k = 0; k < n-1; k++)
		{
			cout << A[k] << ' ';
		}
	cout << A[n-1] << endl;

	for(int i = 1; i < n; i++)
	{
		j = i-1;
		temp = A[i];
		while(j >= 0 && A[j] > temp)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;

		for(int k = 0; k < n-1; k++)
		{
			cout << A[k] << ' ';
		}
		cout << A[n-1] << endl;
	}

	return 0;
}
