#include<iostream>
using namespace std;


void print(int* a, int n)
{
	int i = 0;
	for (i; i < n; i++)
	{
		if (i > 0)
			cout << ' ';
		cout << a[i];
	}
	cout << endl;
}

void inssert(int* a, int n)
{
	int i, j, v;
	for (int i = 1; i < n; i++)
	{
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		print(a, n);
	}
}

int main()
{
	int n, i, j;
	int a[100];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	print(a, n);
	inssert(a, n);
	return 0;
}
