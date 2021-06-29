#include<iostream>
using namespace std;
static const int MAX = 100;

int Bubblesort(int a[], int n)
{
	int flag = 1, i = 0;
	int res = 0;
	while (flag) {
		flag = 0;
		for (int j = n - 1;j > i;j--)
		{
			if (a[j] < a[j - 1])
			{
				int p = a[j - 1];
				a[j - 1] = a[j];
				a[j] = p;
				flag = 1;
				res++;
			}
		}
		i++;
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
	int res = Bubblesort(a, n);
	for (int i = 0;i < n;i++)
	{
		if (i > 0) cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << res<<endl;
}
