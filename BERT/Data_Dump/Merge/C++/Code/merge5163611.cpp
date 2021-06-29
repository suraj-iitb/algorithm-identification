#include<iostream>
using namespace std;
#define MAX 2000000000
#define NU 500000 
int count;
void Merge(int A [],int left,int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	
	int D[n1+1];
	int E[n2+1];
	for(int i=0;i<n1;i++) D[i]=A[left+i];
	for(int i=0;i<n2;i++) E[i]=A[mid+i];
	D[n1]=MAX;
	E[n2]=MAX;
	
	int i=0,j=0;
	for(int k=left;k<right;k++)
	{
		count++;
		if(D[i]<=E[j])
		{
			A[k]=D[i++];
		}
		else 
		{
			A[k]=E[j++];		
		}		
	}
}
void Mergesort(int A[],int left,int right)
{
	if(left+1 < right)
	{
		int mid=(left+right)/2;
		Mergesort(A,left,mid);
		Mergesort(A,mid,right);
		Merge(A,left,mid,right);
	}
}
int main()
{
	int n;
	count=0;
	cin>>n;
	int A[NU];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	Mergesort(A,0,n);
	for(int i=0;i<n;i++)
	{
		if(i)cout<<" ";
		cout<<A[i];
	}
	cout<<endl;
	cout<<count<<endl;
	return 0;
}
