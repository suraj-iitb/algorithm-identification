#include<iostream>
using namespace std;
static const int MAX = 100;

int SelectionSort(int a[], int n)
{
	int min = 0, res = 0;
	for (int i = 0;i < n;i++) {
		int flag = 0;
		int min = i;
		for (int j = i;j < n;j++)
		{
			if (a[j] < a[min])
			{
				min = j;
				flag = 1;
			}
		}
		
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		if(flag ==1) res++;
	}
	return res;
}

int main()
{
	int n, a[MAX];
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int res = SelectionSort(a, n);
	for (int i = 0;i < n;i++)
	{
		if(i > 0) cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << res << endl;
	return 0;
}
