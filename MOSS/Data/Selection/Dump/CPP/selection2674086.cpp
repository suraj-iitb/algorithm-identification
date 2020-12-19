#include<iostream>

using namespace std;

int main()
{
	int n,t,min,cnt=0;
	int arr[100] = { 0 };

	cin >>n;
	for (int i = 0; i != n; ++i)
	{
		cin >> arr[i];
	}
	
	for (int i = 0; i != n - 1; ++i)
	{
		min = i;
		for (int j = i+1; j != n; ++j)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			++cnt;
			t = arr[i];
			arr[i] = arr[min];
			arr[min] = t;
		}
		
	}

	for (int i = 0; i != n; ++i)
	{
		cout << arr[i];
		if (i == n - 1)
		{
			cout << endl;
			break;
		}
		cout << " ";
	}
	cout << cnt << endl;

	return 0;

}
