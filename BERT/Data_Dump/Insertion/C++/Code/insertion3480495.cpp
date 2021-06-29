#include <iostream>
using namespace std;
const int MAX = 110;
int a[MAX];
void insertionSort(int a[], int n)
{
	int key, j;
	for(int i = 1; i < n; ++ i)
	{
		key = a[i];
		j = i - 1;
		while(a[j] > key && j >= 0)
		{
			a[j + 1] = a[j];
			j --;
		}
		a[j + 1] = key;
		for(int k = 0; k < n; ++ k)
		{
			if(k == n - 1)
				cout << a[k];
			else
				cout << a[k] << " ";
		}
		cout << endl;
	}
	return ;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++ i)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; ++ i)
	{
		if(i == n - 1)
			cout << a[i];
		else
			cout << a[i] << " ";
	}
	cout << endl;
	
	insertionSort(a, n);
	
	return 0;
} 
