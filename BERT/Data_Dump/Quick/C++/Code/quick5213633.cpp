#include<iostream>
#include<algorithm>
#define MAX 2000000000
#define NU 100000 
using namespace std;

struct card{
	char suit;
	int value;
};
card D[NU/2+2],E[NU/2+2];

void Merge(card A [],int left,int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++) D[i]=A[left+i];
	for(int i=0;i<n2;i++) E[i]=A[mid+i];
	D[n1].value=MAX;
	E[n2].value=MAX;
	
	int i=0,j=0;
	for(int k=left;k<right;k++)
	{
		if(D[i].value<=E[j].value)
		{
			A[k]=D[i++];
		}
		else 
		{
			A[k]=E[j++];		
		}		
	}
}
void Mergesort(card A[],int left,int right)
{
	if(left+1 < right)
	{
		int mid=(left+right)/2;
		Mergesort(A,left,mid);
		Mergesort(A,mid,right);
		Merge(A,left,mid,right);
	}
}
int partition(card A [],int p,int r)
{
	int i=p-1;
	card t;
	int x=A[r].value;
	for(int j=p;j<r;j++)
	{
		if(A[j].value<=x)
		{
			i++;
			t=A[i];
			A[i]=A[j];
			A[j]=t;
		}
	}
	t=A[i+1];
	A[i+1]=A[r];
	A[r]=t;
	return i+1;
	
}

void Quicksort(card A[],int p,int r)
{
	if(p<r)
	{
		int q= partition(A,p,r);
		Quicksort(A,p,q-1);
		Quicksort(A,q+1,r);
	}
 } 

int main()
{
	card A[NU],B[NU];
	int n;
	cin>>n;
	int stable=1;
	for(int i=0;i<n;i++)
	{
		cin>>A[i].suit>>A[i].value;
		B[i]=A[i];
	}
	Quicksort(A,0,n-1);
	Mergesort(B,0,n);
	for(int i=0;i<n;i++)
	{
		if(A[i].suit!=B[i].suit)stable=0;
	}
	if(stable==1)cout<<"Stable"<<endl;
	else cout<<"Not stable"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<A[i].suit<<" "<<A[i].value<<endl;
	}

	return 0;
}
