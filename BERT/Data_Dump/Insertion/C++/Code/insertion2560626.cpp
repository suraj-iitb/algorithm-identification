#include <iostream>
using namespace std;

void display(int A[], int n)
{
	for(int i = 1; i <= n; i++)
	{
		cout << A[i];
		if(i < n)
		{
			cout << " ";
		}
	}
	cout << endl;
}

int main(void)
{
	int N = 1000;
	int n;
	int A[N];

	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	for(int j = 1; j <= n; j++)
	{
		int v = A[j];
		int k = j-1;
		while(k >= 1 && A[k] > v)
		{
			A[k+1] = A[k];
			k--;
		}
		A[k+1] = v;
		display(A, n);
	}
	return 0;
}
