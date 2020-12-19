#include<iostream>

using namespace std;

int main()
{
	int n,t,cnt=0;
	int arr[100] = { 0 };

	cin >>n;
	for (int i = 0; i != n; ++i)
	{
		cin >> arr[i];
	}
	
	for (int i = 0; i != n - 1; ++i)
	{
		for (int j = n-1; j != 0; --j)
		{
			if (arr[j] < arr[j-1])
			{
				++cnt;
				t = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = t;
			}
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
