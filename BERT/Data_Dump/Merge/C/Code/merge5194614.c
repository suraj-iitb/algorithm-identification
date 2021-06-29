#include <stdio.h>
#define N 500001
#define INF 10000000000

int A[N], c = 0;

void merge(int l, int m, int r)
{
	int i, j, k, n1 = m - l, n2 = r - m;
	int L[N], R[N];
  
	for(i = 0; i < n1; i++) L[i] = A[l + i];
	for(i = 0; i < n2; i++) R[i] = A[m+ i];
  
	L[n1] = R[n2] = INF;
	i = j = 0;
	
	for(k = l; k < r; k++)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i += 1;
		}
		else
		{
			A[k] = R[j];
			j += 1;
		}
		c++;
	}
}

void mergeSort(int l, int r)
{
	int m;
	
	if(l + 1 < r)
	{
		m = (l + r) / 2;
		mergeSort(l, m);
		mergeSort(m, r);
		merge(l, m, r);
	}
}

int main()
{
	int i, n;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &A[i]);
	mergeSort(0, n);
	
	for(i = 0; i < n; i++)
	{
		printf("%d", A[i]);
		if(i < n - 1){
			printf(" ");
		}
		else printf("\n");
  }
	
	printf("%d\n", c);
	
	return 0;
}
