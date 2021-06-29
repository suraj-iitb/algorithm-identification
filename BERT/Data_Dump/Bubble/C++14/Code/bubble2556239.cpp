#include<iostream>
using namespace std;

int main()
{
	int n=0;cin>>n;
	int a[100]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int cnt=0,f=1;
	for(int j=0;f==1;j++)
	{
		f=0;
		for(int i=n-1;i>j;i--)
		{
			if(a[i]<a[i-1])
			{
				cnt++;
				swap(a[i],a[i-1]);
				f=1;
			}
		}
	}
	
	cout<<a[0];
	for(int i=1;i<n;i++)
	{
		cout<<" "<<a[i];
	}
	cout<<endl<<cnt<<endl;
	return 0;
}
