#include<stdio.h>

int sentinel=2000000000;
int L[250002],R[250002];
int cnt;

void merge(int A[],int left,int mid,int right)
{
	int n1=mid-left;
	int n2=right-mid;
	int i,j,k;
	
	for(i=0;i<n1;i++)
	{
		L[i]=A[left+i];
	}
	for(i=0;i<n2;i++)
	{
		R[i]=A[mid+i];
	}
	L[n1]=sentinel;
	R[n2]=sentinel;
	i=0;
	j=0;
	
	for(k=left;k<right;k++)
	{
		cnt++;
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
	}
}

void mergeSort(int A[],int left,int rigft)
{
	if(left+1<rigft)
	{
		int mid=(left+rigft)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,rigft);
		merge(A,left,mid,rigft);
	}
}

int main(void)
{
	int n,i;
	int A[500000];
	cnt=0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	mergeSort(A,0,n);
	
	for(i=0;i<n-1;i++)
	{
		printf("%d ",A[i]);
	}
	printf("%d\n%d\n",A[i],cnt);
	
	return 0;
}
