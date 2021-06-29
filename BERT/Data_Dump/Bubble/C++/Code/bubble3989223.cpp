#include<iostream>
using namespace std;
int Bubble(int a[], int n)
{
	int sew = 0;
	int flag = 1;
	for (int i = 0; flag; i++)
	{
		flag = 0;
		for (int j = n - 1; j >= i + 1; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				flag = 1;
				sew++;
			}
		}
	}
	return sew;
}
int main()
{
	int a[100], n, sew;
	cin >> n;
	for (int i = 0; i < n ; i++)
	{
		cin >> a[i];
	}
	sew = Bubble(a, n);
	for (int i = 0; i < n ; i++)
	{
		if (i)
		{
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl;
	cout << sew << endl;
	return 0;
}
