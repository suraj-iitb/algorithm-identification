#include<stdio.h>
#define INFTY 1000000000
typedef struct poke 
{
	char f;
	int x;
}pk;

pk A[100005], B[100005];
int stable=1;

int partition(pk A[100005], int p, int r)
{
	int x=A[r].x, i=p-1, j, m;
	char mf;
	for(j=p;j<r+1;j++)
	{
		if(A[j].x<=x)
		{
			i++;
			m=A[i].x;
			mf=A[i].f;
			A[i].x=A[j].x;
			A[i].f=A[j].f;
			A[j].x=m;
			A[j].f=mf;
		}
	}
	return i;
}

void quick_sort(pk A[100005],int p, int r)
{
    if(p<r)
	{
		int q=partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}	
}

void merge(pk A[500005],int left,int mid,int right)
{
	int i, j, k, n1=mid-left, n2=right-mid;
	pk B[n1], C[n2];
	for(i=0;i<n1;i++)
	{
		B[i].f=A[left+i].f;
		B[i].x=A[left+i].x;
	} 
	for(i=0;i<n2;i++)
	{
		C[i].f=A[mid+i].f;
		C[i].x=A[mid+i].x;
	} 
	B[n1].x=INFTY;
	C[n2].x=INFTY;
	i=0;
	j=0; 
	for(k=left;k<right;k++)
	{
		if(B[i].x<=C[j].x)
		{
			A[k].f=B[i].f;
			A[k].x=B[i].x;
			i++;
		}
		else
		{
			A[k].f=C[j].f;
			A[k].x=C[j].x;
			j++; 
		}
	}
}

void merge_sort(pk A[500005], int left, int right)
{
	if(left<right-1)
	{
		int mid=(left+right)/2;
		merge_sort(A,left,mid);
		merge_sort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int main()
{
	int n, i, v;
	char S[10];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %d",S, &v);
		A[i].f=S[0];
		A[i].x=v;
		B[i].f=S[0];
		B[i].x=v;
	}
	quick_sort(A,0,n-1);
	merge_sort(B,0,n);
	for(i=0;i<n;i++)
	{
		if(A[i].f!=B[i].f) stable=0;
	}
	if(stable==0)
	{
		printf("Not stable\n");
	}
	else printf("Stable\n");
	for(i=0;i<n;i++)
	{
		printf("%c %d\n",A[i].f, A[i].x);
	}
	return 0;
}
