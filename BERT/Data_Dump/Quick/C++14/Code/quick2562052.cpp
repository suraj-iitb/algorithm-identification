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
#define SIZE 100000
struct card{char suit;int num;};

card L[SIZE/2+2],R[SIZE/2+2];

int merge(card a[],int l,int m,int r)
{
	int n1=m-l;
	int n2=r-m;
	for(int i=0;i<n1;i++)
	{
		L[i]=a[l+i];
	}
	L[n1].num=MAX;
	for(int i=0;i<n2;i++)
	{
		R[i]=a[m+i];
	}
	R[n2].num=MAX;
	int i=0,j=0;
	for(int k=l;k<r;k++)
	{
		if(L[i].num<=R[j].num)
		{
			a[k]=L[i++];
		}
		else
		{
			a[k]=R[j++];
		}
	}
}

int mergeS(card a[],int l,int r)
{
	if(l+1<r)
	{
		int m=(l+r)/2;
		mergeS(a,l,m);
		mergeS(a,m,r);
		merge(a,l,m,r);
	}
}

int part(card a[],int p,int r)
{
	int x=a[r].num;
	int i=p-1;
	for(int j=p;j<r;j++)
	{
		if(a[j].num<=x)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);	
	return i+1;
}

int quickS(card a[],int p,int r)
{
	if(p<r)
	{
		int q=part(a,p,r);
		quickS(a,p,q-1);
		quickS(a,q+1,r);
	}
}

int main()
{
	int n;cin>>n;card a[SIZE];card b[SIZE];
	for(int i=0;i<n;cin>>a[i].suit>>a[i].num,i++);
	for(int i=0;i<n;b[i]=a[i],i++);
	quickS(a,0,n-1);
	mergeS(b,0,n);
	int err=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].suit!=b[i].suit)err=1;
	}
	if(err==0)cout<<"Stable"<<endl;
	else cout<<"Not stable"<<endl;
	for(int i=0;i<n;cout<<a[i].suit<<" "<<a[i].num<<endl,i++);
	return 0;
}
