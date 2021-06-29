#include<iostream>
using namespace std;

int main()
{
	int N;
	int A[100000];
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	int j, v;
	for (int i = 0; i<N - 1; i++)
		cout << A[i] << ' ';
	cout << A[N - 1] << endl;
	for (int i = 1; i < N; ++i)
	{
		j = i - 1;
		v = A[i];
		while (j >= 0 && A[j] > v)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		for (int i = 0; i<N - 1; i++)
			cout << A[i] << ' ';
		cout << A[N - 1] << endl;
	}
	return 0;
}
