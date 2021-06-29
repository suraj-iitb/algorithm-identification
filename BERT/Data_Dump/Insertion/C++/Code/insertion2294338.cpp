#include <iostream>
using namespace std;
void insertionSort(int *arr,int n)
{
	void printTrace(int *arr,int n);
	int v;
	int i,j;
	for(i=1; i<n; i++)
	{
		v = arr[i];
		j = i-1;
		while(j>=0&&arr[j]>v)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = v;
		printTrace(arr,n);
	}
}
void printTrace(int *arr,int n)
{
	for(int i=0; i<n; i++)
	{
		if(i>0) cout << " ";
		cout << arr[i];
	}
	cout << "\n" ;
}
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	printTrace(arr,n);
	insertionSort(arr,n);
	return 0;
}
