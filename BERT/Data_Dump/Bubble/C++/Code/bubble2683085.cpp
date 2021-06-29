#include <iostream>

using namespace std;

int a[105], n;

int main()
{
	int i, cnt;
	cin >> n;
	int bubblesort();
	for(i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cnt = bubblesort();
	for(i = 0; i < n; i++)
	{
		if(i > 0)
		{
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl;
	cout << cnt << endl;
}

int bubblesort()
{
	int i, j, cnt = 0, tmp;
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - 1 - i; j++)
		{
			if(a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				cnt++;
			}
		}
	}
	return cnt;
}
