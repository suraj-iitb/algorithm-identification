#include <iostream>

using namespace std;

int main()
{
	int i, a[105], n, j, v;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(j > 0)
			{
				cout << " ";
			}
			cout << a[j];
		}
		cout << endl;
		v = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > v)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
	for(i = 0; i < n; i++)
	{
		if(i > 0)
		{
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl;
	
	return 0;
}
