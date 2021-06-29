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
int selectSort(int* a, int n)
{
	int m = 0;
	int min,t,k;
	for (int i = 0; i < n-1; i++)
	{
		min = a[i];
		k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				k = j;
			}	
		}
		if (min != a[i])
		{
			t = a[k];
			a[k] = a[i];
			a[i] = t;
			m++;
		}	
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
	int m = selectSort(a, n);
	print(a, n);
	cout << m << endl;
	return 0;
}
