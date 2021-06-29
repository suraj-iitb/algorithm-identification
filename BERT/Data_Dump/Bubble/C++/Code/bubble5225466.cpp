#include<iostream>
#include<algorithm>
using namespace std;


void showshow(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i > 0) cout << " ";
		cout << a[i];
	}
}
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int flag = 1;
	int count = 0;
	int t;
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < (n - 1); i++)
		{
			if (a[i] > a[i + 1])
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
				flag = 1;
				count++;
			}
		}
	}
	showshow(a, n);
	cout << endl;
	cout << count<<endl;
	return 0;
	}

