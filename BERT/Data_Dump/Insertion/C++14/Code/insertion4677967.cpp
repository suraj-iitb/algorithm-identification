// Written by Cesur
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define all(var) var.begin(),var.end()
#define f(i,l,n) for(int i=l;i<n;i++)
#define revloop(var,l,n) for(int var=l;var>=n;var--)
#define scan(var) scanf("%d",&var)
#define scan2(var,var2) scanf("%d %d",&var,&var2)
#define scanvector(var,n) f(i,0,n)scanf("%d",&var[i])
#define printvector(var,n) f(i,0,n)printf("%d ",var[i])
#define scanvectorlong(var,n) f(i,0,n)scanf("%lld",&var[i])
#define printvectorlong(var,n) f(i,0,n)printf("%lld ",var[i])
#define print(var) printf("%d\n",var)
#define print2(var,var2) printf("%d %d\n",var,var2)
#define mp(var,var2) make_pair(var,var2)
#define ll long long 
#define pairint pair<int,int>
#define pairlong pair<long long,long long>
#define debug(zz) cout<<#zz<<" == "<<zz<<endl;
#define M 1000000007

void printer(vector<int>&v,int n)
{
	for(int i=0;i<n-1;i++)
	{
	    printf("%d ",v[i]);
	    
	}
	cout<<v[n-1]<<endl;
}

void insertionSort(vector<int>&v,int n)
{
	printer(v,n);

	for(int i=1;i<n;i++)
	{
		int curr=v[i];
		int j=i;
		while(j && v[j-1]>curr)
		{
			v[j]=v[j-1];
			j--;
		}
		v[j]=curr;
		printer(v,n);
	}

}

int main()
{
	int n;
	scan(n);
	vector<int>v(n);
	scanvector(v,n);
	insertionSort(v,n);

}
