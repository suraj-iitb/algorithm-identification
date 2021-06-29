#include<stdio.h>
#define INFTY 1000000000
int A[500005], m=0 ,q;
void merge(int A[500005],int left,int mid,int right)
{
	int i, j, k, n1=mid-left, n2=right-mid;
	int B[n1], C[n2];
	for(i=0;i<n1;i++)
	{
		B[i]=A[left+i];
	} 
	for(i=0;i<n2;i++)
	{
		C[i]=A[mid+i];
	} 
	B[n1]=INFTY;
	C[n2]=INFTY;
	i=0;
	j=0; 
	for(k=left;k<right;k++)
	{
		if(B[i]<C[j])
		{
			A[k]=B[i];
			i++;
			m++;
		}
		else
		{
			A[k]=C[j];
			j++;
			m++; 
		}
	}
}

void merge_sort(int A[500005], int left, int right)
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
	int n, i;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", A+i);
	}
	merge_sort(A,0,n);
	for(i=0;i<n;i++)
	{
		if(i>0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n%d\n", m);
	return 0;
 } 
