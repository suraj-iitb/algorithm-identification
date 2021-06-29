#include<bits/stdc++.h>
using namespace std;
#define Max 500005
#define SENTINEL 2000000000 
int L[Max/2+2],R[Max/2+2];
int cnt; //统计交换次数 
int n;

void merge(int A[],int left,int mid,int right)
{
	int n1 = mid-left;
	int n2 = right-mid;
	for(int i = 0;i<n1;i++)
	{
		L[i] = A[left+i];
	}
	for(int i = 0;i<n2;i++)
	{
		R[i] = A[mid +i];
	}
	L[n1] = R[n2] = SENTINEL;
	int i = 0,j= 0;
	for(int k = left;k<right;k++)
	{
		cnt++;
		if(L[i]<=R[j])
		{
			A[k] = L[i++];
		}
			else{
				A[k] = R[j++];
			}
	}
}

void mergeSort(int A[],int left,int right)
{
	if(left+1<right)
	{
		int mid = (left +right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int main()
{
	int A[Max],n,i;
	cnt = 0;
	
	cin>>n;
	for(int i =0;i<n;i++)cin>>A[i];
	
	mergeSort(A,0,n);
	
	for(i= 0;i<n;i++)
{
	if(i)cout<<' ';
	cout<<A[i];
}
	cout<<endl;
	cout<<cnt<<endl;
	return 0 ;	
	
}



