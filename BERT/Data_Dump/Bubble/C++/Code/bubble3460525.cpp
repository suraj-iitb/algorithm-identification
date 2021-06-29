#include<iostream>
using namespace std;
static const int N = 100;

int main()
{
	int A[N], n, time, flag;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> A[i];

	time = 0;
	flag = 1;
	while (flag)
	{
		flag = 0;
		for (int j = n - 1; j > 0; j--)
		{
			if (A[j] < A[j - 1])
			{
				int temp;
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				flag = 1;

				time++;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
		cout << A[i] << " ";
	cout << A[n - 1] << endl;
	cout << time <<endl;

	return 0;
}
