#include<stdio.h>
#define MAX 500000
#define INFTY 1000000000

int L[MAX/2+2];
int R[MAX/2+2];
int count;

void merge(int S[], int left, int mid, int right)
{
	int n1 = mid-left;
	int n2 = right-mid;
	
	for(int i=0; i<n1; i++)
	{
	
		L[i] = S[left+i];
	
	}
	for(int i=0; i<n2; i++)
	{
	
		R[i] = S[mid+i];
	
	}
	
	L[n1] = INFTY;
	R[n2] = INFTY;

	int i=0;
	int j=0;
	
	for(int k=left; k< right; k++)
	{
		
		count++;
		
		if(L[i] <= R[j])
		{
			S[k] = L[i];
			
			i++;
		}
		else
		{
			S[k] = R[j];
			
			j++;
		}
	}
}

void mergesort(int S[], int left, int right)
{

	if(left+1 < right)
	{
	
		int mid = (left+right)/2;
		
		mergesort(S,left, mid);
		mergesort(S, mid, right);
		merge(S,left, mid, right);
	}



}

int main(void)
{

int n;

scanf("%d", &n);

int S[MAX];

	count=0;
	
for(int i=0; i<n; i++)
{
	scanf("%d", &S[i]);
}

	mergesort(S, 0, n);
	
	for(int i=0; i<n; i++)
	{
		if(i>0)
		{
			printf(" ");
		}
		
			printf("%d", S[i]);
	
	}
	
	printf("\n");
	
	printf("%d\n", count);
	

return 0;

}
