#include<iostream>

using namespace std;
int main()
{	
	int n,a[100],v;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int i,j;
	for (int i = 0; i < n; ++i)
		{
			if(i!=n-1) cout<<a[i]<<" ";
			else cout<<a[i]<<endl;
		}
	for(i=1;i<n;++i)
	{
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for (int i = 0; i < n; ++i)
		{
			if(i!=n-1) cout<<a[i]<<" ";
			else cout<<a[i]<<endl;
		}
	}
	return 0;
}
