#include <stdio.h>
#define MAX 500000
#define N 1000000000

int L[MAX/2+2],R[MAX/2+2];
int c;

void merge(int A[],int n,int l,int m,int r);
void mergeSort(int A[],int n,int l,int r);

int main()
{
	int A[MAX],n,i;
	c=0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	mergeSort(A,n,0,n);
	
	for(i=0;i<n;i++)
	{
	if(i)
		{
			printf(" ");
		}
		printf("%d",A[i]);
	}
	
	printf("\n");
	printf("%d\n",c);

}

void merge(int A[],int n,int l,int m,int r)
{
	int i,j,k;
	int n1=m-l;
	int n2=r-m;
	
	for(i=0;i<n1;i++)
	{
		L[i] = A[l+i];
	}
	
	for(i=0;i<n2;i++)
	{
		R[i] = A[m+i];
	}
	
	L[n1]=R[n2]=N;
	
	for(i=0,j=0,k=l;k<r;k++)
	{
		c++;
		if(L[i]<=R[j])
		{
			A[k]=L[i++];
		}
		else
		{
			A[k]=R[j++];
		}
	}

}

void mergeSort(int A[],int n,int l,int r)
{
	int m;
	
	if(l+1<r)
	{
		m=(l+r)/2;
		mergeSort(A,n,l,m);
		mergeSort(A,n,m,r);
		merge(A,n,l,m,r);
	}
}

