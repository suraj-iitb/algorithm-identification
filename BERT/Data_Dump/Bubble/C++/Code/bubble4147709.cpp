#include<iostream>
using namespace std;

void print(int* a, int n);
void print(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << ' ';
		cout << a[i];
	}
	cout << endl;
}

int BubbleSort(int* a, int n)
{
	int m = 0;
	int t = 0;
	int flag = n-1;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < flag; j++)
		{
			if (a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				m++;
				t = j + 1;
			}
		}
		flag = t;
	}
	return m;
}

int main()
{
	int a[100];
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int m=BubbleSort(a, n);
	print(a, n);
	cout << m << endl;
	return 0;
}

