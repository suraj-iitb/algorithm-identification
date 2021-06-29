#include<iostream>
using namespace std;
void insertsionSort(int a[], int n)
{
	int v,j;
	for(int i=1; i<n; i++)
	{
		v = a[i];
		j=i-1;
		
		while((j >= 0)&&(a[j] > v))
		{
			a[j+1] = a[j];
			j--;
		}
		
		a[j+1] = v;
		
		for(int i=0; i<n; i++)
		{
			if(i != 0)
			cout << " ";
			cout << a[i];
		}
		cout << endl; 
	}
}
int main()
{
	int n;
	
	
	cin >> n;
	
	int a[n] = {0};
	
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	for(int i=0; i<n; i++)
	{
		if(i != 0)
		cout << " ";
		cout << a[i];
	}
	cout << endl;
	
	insertsionSort(a,n);
	
}
