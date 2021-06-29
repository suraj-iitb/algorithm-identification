#include <iostream>
using namespace std;
#include <cstdio>
void insert(int* a, int n)
{
	
	for (int i = 1;i < n;i++)
	{
		for (int m = 0;m < n;m++)
		{
			if (m > 0)
				printf(" ");
			printf("%d", a[m]);
		}
		cout << endl;
		int v = a[i];
		int j=i-1;
		while(j >= 0&&v < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = v;
	}
}

int main()
{
	int n;
	cin >> n;
	int a[100];
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	insert(a, n);
	for (int m = 0;m < n;m++)
	{
		if (m > 0)
			printf(" ");
		printf("%d", a[m]);
	}
	cout << endl;
	return 0;
}
