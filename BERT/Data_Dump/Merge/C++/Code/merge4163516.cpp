#include<stdio.h>
#include<stdlib.h>

#define MAX 500000
#define INFTY 2000000000

int R[MAX / 2 + 2];
int L[MAX / 2 + 2];
int cnt = 0;

void merge(int a[], int left, int mid, int right,int n)
{
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++)
	{
		L[i] = a[left + i];
	}
	for (int i = 0; i < n2; i++)
	{
		R[i] = a[mid + i];
	}
	L[n1] = R[n2] = INFTY;
	int i = 0, j = 0;
	for (int k = left; k < right; k++)
	{
		cnt++;
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}	
		else
		{
			a[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int a[], int left, int right,int n)
{
	if (right - left > 1)
	{
		int mid = (right + left) / 2;
		mergeSort(a, left, mid,n);
		mergeSort(a, mid, right,n);
		merge(a, left, mid, right,n);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int *a;
	a = (int*)malloc(sizeof(int) * MAX);
	if (a != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		mergeSort(a, 0, n,n);
                for (int i = 0; i < n; i++)
		{
			if (i >0)
				printf(" ");
			printf("%d", a[i]);
		}
		printf("\n%d\n", cnt);
	}
	return 0;
}
