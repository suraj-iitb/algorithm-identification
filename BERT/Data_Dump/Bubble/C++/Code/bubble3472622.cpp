#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <vector>
#include <limits.h>
#define maxn 10000000
#define pi acos(-1)
using namespace std;
double aabs(double x)
{
	if(x<0)return -x;
	return x;
}
int gcd(int a,int b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int main()
{
	int n,ans=0;
	int a[107];
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			int t;
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				ans++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=n)cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

