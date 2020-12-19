#include<iostream>

using namespace std;

int main()
{
	int n, v,a[100] = { 0 };

	cin >> n;
	for (unsigned int i = 0; i != n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i != n; ++i)
	{
		cout << a[i];
		if (i == n - 1)
		{
			cout << endl;
		}
		else
		{
			cout << " ";
		}
	}

	for (int i = 1; i != n; ++i)
	{
		v = a[i];
		for (int j = i - 1; j >= 0&&a[j]>v;)
		{
			a[j + 1] = a[j];
			--j;
			a[j + 1] = v;
		}

		for (int i = 0; i != n; ++i)
		{
			cout << a[i];
			if (i == n - 1)
			{
				cout << endl;
			}
			else
			{
				cout << " ";
			}
		}
		
	
	}

	return 0;

}
