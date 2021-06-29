#include<iostream>
#include<algorithm>
using namespace std;
static const int N = 100;

int main()
{
	int n;
	cin >> n;
	int A[N], v, j;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int c = 0; c < n - 1; c++)
		cout << A[c] << " ";
	cout << A[n - 1] << endl;

	for (int i = 1; i < n; i++)
	{
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		for (int c = 0; c < n - 1; c++)
			cout << A[c] << " ";
		cout << A[n - 1] << endl;
	}

	return 0;
}
