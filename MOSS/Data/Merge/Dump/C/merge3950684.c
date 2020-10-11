#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int c = 0;

void merge(int S[], int min, int mid, int max)
{
	int i, j, k;
	int n1 = mid - min;
	int n2 = max - mid;
	
	for(i = 0; i < n1; i++)
	{
		L[i] = S[min + i];
	}
	for(i = 0; i < n2; i++)
	{
		R[i] = S[mid + i];
	}
	
	L[n1] = SENTINEL;
	R[n2] = SENTINEL;
	i = 0;
	j = 0;
	
	for(k = min; k < max; k++)
	{
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
		c++;
	}
}

void mergeSort(int S[], int min, int max)
{
	if(min + 1 < max)
	{
		int mid = (min + max) / 2;
		mergeSort(S, min, mid);
		mergeSort(S, mid, max);
		merge(S,min, mid, max);
	}
}

int main(void)
{
	int n, i;
	
	scanf("%d", &n);
	int S[n];
	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &S[i]);
	}
	
	mergeSort(S,  0, n);
	
	for(i = 0; i < n; i++)
	{
		if(i != n - 1)
		{
			printf("%d ", S[i]);
		}
		else
		{
			printf("%d\n", S[i]);
		}
	}
	
	printf("%d\n", c);
	
	return 0;
}
