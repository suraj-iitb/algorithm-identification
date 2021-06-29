#include<iostream>
long long a[100000], as;
using namespace std;
int main()
{
	long long n;
	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (long long i = 0; i < n; i++)
	{
		long long mi = i;		
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[mi])
			{
				mi = j;
			}
		}
		if (mi != i)
		{
			long long temp = a[i];
			a[i] = a[mi];
			a[mi] = temp;
			as++;
		}
	}
	for (long long i = 0; i < n; i++)
	{
		cout << a[i] << (i < n - 1 ? ' ' : '\n');
	}
	cout << as << endl;
	return 0;
}
