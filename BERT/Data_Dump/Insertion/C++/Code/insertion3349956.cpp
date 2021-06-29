#include<iostream>
#include<algorithm>
using namespace std;
static const int N = 105;
int main()
{
	int a[N];
	int n,v,j,k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(i<n-1)
		cout<<a[i]<<' ';
		else
		cout<<a[i]<<endl;
		
	}
	for(int i=1;i<n;i++)
	{
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for( j=0;j<n-1;j++)
		{
			cout<<a[j]<<' ';
		}
		cout<<a[j]<<endl;
		/*if(i<n-1)
		{
			cout<<a[j]<<endl;
		}
		else 
		cout<<a[j];*/
	}
	
}
