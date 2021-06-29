#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[105];
	int n,count=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		int minj = i;
		for (int j = i; j < n; j++)
		{
			if (arr[j] < arr[minj])
			{
				minj = j;
			}
		}
		swap(arr[i], arr[minj]);
		if (i != minj)
		{
			count++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			cout << " ";
		}
		cout << arr[i];
	}
	cout << endl;
	cout << count << endl;
	return 0;
}
