#include <iostream>
using namespace std;
int selectionSort(int* a,int n)
{
	int exchangeCount=0;
	int i,j;
	int minj,temp;
	for(i=0; i<n; i++)
	{
		minj = i;
		for(j=i; j<n; j++)
		{
			if(a[j]<a[minj])
			{
				minj = j;
			}
		}
		if(i!=minj) exchangeCount++;
		temp=a[i];
		a[i]=a[minj];
		a[minj]=temp;
	}
	return exchangeCount;
}
void printArr(int *a,int n)
{
	for(int i=0; i<n; i++)
	{
		if(i>0) cout << " ";
		cout << a[i];
	}
	cout << "\n";
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	int count=selectionSort(a,n);
	printArr(a,n);
	cout << count << endl;
	return 0;
}
