#include<iostream>
using namespace std;
void PrintArray(int* a,int n)
{
	for(int i=1;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[n]<<endl;
}

int main()
{
	int a[101];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		a[0]=a[i];
		int j=i;
		while(a[j-1]>a[0])
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=a[0];
		PrintArray(a,n);
	}
	return 0;
}
