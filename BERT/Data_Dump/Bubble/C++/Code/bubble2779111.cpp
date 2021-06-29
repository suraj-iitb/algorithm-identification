#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
	int n, tmp, count = 0;
	int A[MAX];
	cin >> n;
	for(int i = 0; i < n ; i++)
		cin >> A[i];

	for(int i = 0; i < n; i++)
	{
		for(int j = n-1; j >= i+1; j--)
		{
			if(A[j] < A[j-1])
			{
				count++;
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
			}
		}
	}

	for(int i = 0; i < n-1; i++)
	{
		cout << A[i] << ' ';
	}
	cout << A[n-1] << endl;
	cout << count << endl;
}
