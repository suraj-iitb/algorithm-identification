#include<stdio.h>
#include<iostream>
using namespace std;
#define N 100
int main()
{
	int num[N];
	int i;
	int n;
	int j;
	int sw;
	int min;
	int a=0;
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cin >> num[i];
	}
	for (i = 0;i < n-1;i++)
	{
		min = i;
		for (j = i + 1;j < n;j++)
		{
			if (num[j] < num[min])
			{		
				min = j;
			}
		}
		if (min != i)
		{
			sw = num[min];
			num[min] = num[i];
			num[i] = sw;
			a++;
		}
	}
	for (i = 0;i < n;i++)
	{
		if (i > 0)
			cout << " ";
		cout << num[i];
	}
	cout << endl;
	cout << a << endl;
    return 0;
}
