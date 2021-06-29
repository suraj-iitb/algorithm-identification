#include<bits/stdc++.h>

using namespace std;

int a[100];

int main()
{
	int n,x,j;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n-1;i++)
		cout<<a[i]<<' ';
	cout<<a[n-1]<<endl;
	for(int i=1;i<n;i++)
	{
		x=a[i];
		j=i-1;
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
		for(int k=0;k<n-1;k++)
			cout<<a[k]<<' ';
		cout<<a[n-1]<<endl;
	}
} 
