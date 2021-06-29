#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <vector>
#define pi acos(-1)
using namespace std;
double aabs(double x)
{
	if(x<0)return -x;
	return x;
}
int main()
{
	int a[107];
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int x=a[i];
		int j=i-1;
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
		for(int k=0;k<n;k++)
		{
			if(k!=n-1)cout<<a[k]<<" ";
			else cout<<a[k]<<endl;
		}
	}
	return 0;
}

