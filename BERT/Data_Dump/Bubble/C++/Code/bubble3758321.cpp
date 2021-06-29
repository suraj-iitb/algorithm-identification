#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[100];
	int flag=1,ans=0,n;
	cin>>n;
	int t;
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(flag)
	{
		flag=0;
		for(int i=n-1;i>0;i--)
			if(a[i]<a[i-1])
			{
				t=a[i];
				a[i]=a[i-1];
				a[i-1]=t;
				flag=1;
				ans++;
			}
	}
	for(int i=0;i<n-1;i++)
		cout<<a[i]<<' ';
	cout<<a[n-1]<<endl;
	cout<<ans<<endl;
}
