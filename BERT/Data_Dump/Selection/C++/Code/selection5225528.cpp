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
	int count = 0;
	int t;
	int min ;
	
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min]) min=j;
		}
		if (a[min] < a[i])
		{
			t = a[min];
			a[min] = a[i];
			a[i] = t;
			count++;
		}
	}
	showshow(a, n);
	cout << endl;
	cout << count<<endl;
	return 0;
	}

