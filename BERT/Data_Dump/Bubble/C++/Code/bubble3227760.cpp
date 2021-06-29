#include<iostream>
using namespace std;
#define N 100
int main()
{
	int n;
	int i;
	int j;
	int swap;
	int a=0;
	int num[N];
	cin >> n;
	for (i = 0;i < n;i++)
	{
		cin >> num[i];
	}
	for (i = 0;i<n;i++)
	{
		for (j = n - 1;j > i ;j--)
		{
			if (num[j] < num[j - 1])
			{
				swap = num[j];
				num[j] = num[j - 1];
				num[j - 1] = swap;
				a++;
			}
		}
	}
	for (i = 0;i < n;i++)
	{
		if (i > 0)
		{
			cout << " ";
		}
		cout << num[i];
	}
	cout << endl;
	cout << a<<endl;

    return 0;
}
