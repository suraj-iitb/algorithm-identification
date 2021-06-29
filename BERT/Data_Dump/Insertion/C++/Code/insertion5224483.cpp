#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t,n,j;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}


		for (int i = 0; i < n; i++)
		{
			if (i == n - 1) { cout << a[i] << endl; }
			else { cout << a[i] << " "; }
		}
		for (int i = 1; i < n; i++)
		{
			j = i - 1;
			t = a[i];
			while (a[j] > t && j >= 0)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = t;
			for (int i = 0; i < n; i++)
			{
				if (i == n - 1) { cout << a[i] << endl; }
				else { cout << a[i] << " "; }
			}
		}
	}


