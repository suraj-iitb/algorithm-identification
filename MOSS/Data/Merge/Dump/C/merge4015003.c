#include<stdio.h>

int count=0;
int merge(int *A,int left,int mid,int right)
{
	int L[500000],R[500000];
	int n1,n2,i,j,k;
	n1=mid-left;
	n2=right-mid;
	for(i=0;i<n1;i++)
	{
		L[i]=A[left+i];
	}
	for(i=0;i<n2;i++)
	{
		R[i]=A[mid+i];
	}
	L[n1]=999999999;
	R[n2]=999999999;
	i=0;
	j=0;
	for(k=left;k<right;k++)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i=i+1;
			count++;
		}
		else
		{
			A[k]=R[j];
			j=j+1;
			count++;
		
		}
	}
}

int mergesort(int *A,int left,int right)
{
	int mid;
	if(left+1<right)
	{
		mid=(left+right)/2;
		mergesort(A,left,mid);
		mergesort(A,mid,right);
		merge(A,left,mid,right);
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n,i;
	int S[500000];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&S[i]);
	}
	mergesort(S,0,n);
	
	for(i=0;i<n-1;i++)
	{
		printf("%d ",S[i]);
	}
	printf("%d\n",S[i]);
	printf("%d\n",count);
	return 0;
}
