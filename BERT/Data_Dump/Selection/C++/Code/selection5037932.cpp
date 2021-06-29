#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int i,j,min,a[1000],cnt=0;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if ( min!= i)
		{
			swap(a[i], a[min]);
			cnt++;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (i != n - 1)
			cout << a[i] << " ";
		else		cout<< a[i];
	}
	cout << endl;
	cout << cnt << endl;
	return 0;
}
