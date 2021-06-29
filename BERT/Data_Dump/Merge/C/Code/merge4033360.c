#include<stdio.h>

#define INFTY 2000000000
#define MAX 500000

int n,count=0;

void merge(int A[],int n,int left, int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	int L[MAX/2+2],R[MAX/2+2];
	int i,j;
	
	for(i=0;i<n1;i++)
	{
		L[i]=A[left+i];
	}
	
	for(i=0;i<n2;i++)
	{
		R[i]=A[mid+i];
	}
	
	L[n1]=INFTY;
	R[n2]=INFTY;
	
	i=0;
	j=0;
	
	for(int k=left;k<right;k++)
	{
		count++;
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i=i+1;
		}
		else
		{
			A[k]=R[j];
			j=j+1;
		}
	}
}

void mergeSort(int A[],int n,int left, int right)
{
	if(left+1<right)
	{
		int mid=(left+right)/2;
		mergeSort(A,n,left,mid);
		mergeSort(A,n,mid,right);
		merge(A,n,left,mid,right);
	}
}

int main(void)
{
	int i;
	
	scanf("%d",&n);
	
	int S[n];
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	
	int left=0,right=n;
	
	mergeSort(S,n,left,right);
	
	for(i=0;i<n;i++)
	{
		printf("%d",S[i]);
		if(i!=n-1)
		{
			printf(" ");
		}
	}
	
	printf("\n");
	printf("%d\n",count);
}
