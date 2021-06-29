#include<iostream>

using namespace std;

const int MAX = 110;
int A[MAX];
int N;

void Print(int a[], int n)
{
	cout << a[0];
	for (int i = 1; i < n; ++i)
		cout << ' ' << a[i];
	cout << endl;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	Print(A, N);
	int tmp, j;
	for (int i = 1; i < N; ++i)
	{
		tmp = A[i];
		j = i - 1;
		while (j >= 0 && tmp < A[j])
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = tmp;
		Print(A, N);
	}
	return 0;
}
