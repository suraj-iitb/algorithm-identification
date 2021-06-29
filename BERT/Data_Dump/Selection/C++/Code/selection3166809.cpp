#include<iostream>
using namespace std;
int selectionSort(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		int temp;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		if (i != min)
			count++;
	}
	return count;
}
int main()
{
	int a[100], n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int count = selectionSort(a, n);
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << " ";
		cout << a[i];
	}
	cout << "\n";
	cout << count << endl;
	return 0;
}
