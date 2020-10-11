#include<stdio.h>
#include<limits.h>

int A[500000];
int L[10000000];
int R[10000000];
int count;

void merge(int left,int  mid, int  right)
{
	int i,j,k,n1,n2;
 	n1 = mid - left;
  	n2 = right - mid;
  	count += right - left;
	
	for (i = 0; i<n1; i++) 
	{
		L[i]=A[left+i];
	}
	for(i = 0; i<n2; i++)
	{
		R[i]=A[mid+i];
 
	}

  	L[n1] = INT_MAX;
  	R[n2] = INT_MAX;
  	i = 0;
  	j = 0;
  	
	for (k = left; k<right; k++)
	{
		if (L[i] <= R[j]) 
		{
			A[k] = L[i];
      		i++;
		}
    else 
		{
      		A[k] = R[j];
      		j++;
		}
	}
}

void mergeSort(int left, int right)
{
	int mid;
	if (left+1 >= right) return;
	
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
}

int main(void)
{
	int i,n;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	count = 0;
	mergeSort(0,n);
	
	for(i=0;i<n;i++)
	{
		if(i==n-1)
		{
			printf("%d\n",A[i]);
		}
		else
		printf("%d ",A[i]);
		
	}
	printf("%d\n",count);
	
	return 0;
}
