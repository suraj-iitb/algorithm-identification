#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 110;
int a[MAX];
int sum;
void SelectionSort(int a[], int n)
{
	int mini;
	for(int i = 0; i < n; ++ i)
	{
		mini = i;
		for(int j = i; j < n; ++ j)
		{
			if(a[j] < a[mini])
			{
				mini = j;
			}
		}
		swap(a[i], a[mini]);
		if(i != mini)
		{
			sum ++;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++ i)
	{
		cin >> a[i];
	}
	
	SelectionSort(a, n);
	
	for(int i = 0; i < n; ++ i)
	{
		if(i == n - 1)
			cout << a[i];
		else
			cout << a[i] << " ";
	}
	cout << endl;
	cout << sum << endl;
	
	return 0;
}
