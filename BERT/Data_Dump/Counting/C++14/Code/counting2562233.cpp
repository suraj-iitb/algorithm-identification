#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
using namespace std;

int a[2000010],b[2000010],c[2000010],n;

int countingS(int a[],int b[],int k)
{
	for(int i=0;i<=k;i++)
	{
		c[i]=0;
	}
	for(int j=1;j<=n;j++)
	{
		c[a[j]]++;
	}
	for(int i=1;i<=k;i++)
	{
		c[i]+=c[i-1];
	}
	for(int j=n;j>=1;j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]--;
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;cin>>a[++i]);
	countingS(a,b,100000);
	for(int i=1;i<=n;i++)
	{
		if(i-1)cout<<" ";
		cout<<b[i];
	}
	cout<<endl;
	return 0;
}
