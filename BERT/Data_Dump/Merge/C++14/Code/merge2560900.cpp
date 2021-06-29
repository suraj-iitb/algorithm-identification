#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
using namespace std;

#define MAX 2000000000
#define SIZE 500000
int cnt;
int L[SIZE/2+2],R[SIZE/2+2];

int merge(int a[],int l,int m,int r)
{
	int n1=m-l;
	int n2=r-m;
	for(int i=0;i<n1;i++)
	{
		L[i]=a[l+i];
	}
	L[n1]=MAX;
	for(int i=0;i<n2;i++)
	{
		R[i]=a[m+i];
	}
	R[n2]=MAX;
	int i=0,j=0;
	for(int k=l;k<r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i++];
		}
		else
		{
			a[k]=R[j++];
		}
		cnt++;
	}
}

int mergeS(int a[],int l,int r)
{
	if(l+1<r)
	{
		int m=(l+r)/2;
		mergeS(a,l,m);
		mergeS(a,m,r);
		merge(a,l,m,r);
	}
}

int main()
{
	int n;cin>>n;int a[SIZE];
	for(int i=0;i<n;cin>>a[i++]);
	mergeS(a,0,n);
	cout<<a[0];
	for(int i=1;i<n;cout<<" "<<a[i++]);
	cout<<endl<<cnt<<endl;
	return 0;
}
