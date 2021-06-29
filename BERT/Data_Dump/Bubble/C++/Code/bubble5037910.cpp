#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int i,a[1000],flag=1,j,cnt=0;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	i = 0;
	while (flag)
	{
		flag = 0;
		for (j = n - 1; j >= i + 1; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				cnt++;
				flag = 1;
			}
		}
		i++;
	}
	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			cout << a[i] << " ";
		else cout << a[i];
	}
	cout << endl;
	cout << cnt<<endl;
	return 0;
}
