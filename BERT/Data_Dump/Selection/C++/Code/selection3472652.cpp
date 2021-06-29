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
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int minj=i,t;
		for(int j=i;j<n;j++)
			if(a[j]<a[minj])
				minj=j;	
		if(minj!=i){t=a[i];
		a[i]=a[minj];
		a[minj]=t;
		ans++;}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)cout<<a[i]<<" ";
		else cout<<a[i]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

