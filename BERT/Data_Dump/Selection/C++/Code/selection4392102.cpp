#include<iostream>
using namespace std; 

int selectionsort(int a[], int n)
{
	int sw = 0;
	
	for(int i=0; i<n; i++)
	{
		int minj = i;
		
		for(int j= i; j < n; j++)
		{
			if(a[j] < a[minj])
			{
				minj = j;
			}
		}
		
		if(i != minj)
		{
			int temp = a[i];
			a[i] = a[minj];
			a[minj] = temp;
			sw++;
		}
	}
	return sw;
}

int main()
{
	int n;
	int sw = 0;
	cin >> n;
	int a[n] = {0};
	for(int i=0; i<n; i++)cin >> a[i];
	
	sw = selectionsort(a,n);
	
	for(int i=0; i<n; i++)
	{
		if(i != 0)cout << " ";
		cout << a[i];
	}
	cout << endl;
	
	cout << sw << endl;
	return 0;
}
