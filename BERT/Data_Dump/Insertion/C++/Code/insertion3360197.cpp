#include<iostream>
using namespace std;
int a[102],n,key;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n-1;i++)
		cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
	for(int i=1;i<n;i++)
	{
		int j=i-1; 
		key=a[i];
		while(j>=0&&a[j]>key)
		{
		a[j+1]=a[j];
		j--;
		}
		a[j+1]=key;
		for(int i=0;i<n-1;i++)
		cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
		
	}	
	return 0;
}
