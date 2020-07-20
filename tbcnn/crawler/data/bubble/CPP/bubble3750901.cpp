#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

int bubbleSort(int a[], int n) 
{
	int cnt = 0;
	bool flag = 1;
	for (int i = 0; flag; i++)
	{
		flag = 0;
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				flag = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int cnt = 0;
	int a[100], n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cnt=bubbleSort(a, n);
	for (int i = 0; i < n; i++)
	{
		if (i)
		{
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl << cnt << endl;
}
