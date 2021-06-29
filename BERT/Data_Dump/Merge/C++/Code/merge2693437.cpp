#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 500000
#define INF 2000000000

int L[MAX/2 + 2], R[MAX/2 + 2];
int cnt = 0;

void merge(int A[],int left,int mid,int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	for(int i = 0; i < n1; i++)
	{
		L[i] = A[left + i];
	}
	for(int i = 0; i < n2; i++)
	{
		R[i] = A[mid + i];
	}
	L[n1] = INF;
	R[n2] = INF;
	int i = 0;
	int j = 0;
	for(int k = left; k < right; k++)
	{
		if(L[i] < R[j])
		{
			A[k] = L[i++];
		}
		else
		{
			A[k] = R[j++];
		}
		cnt++;
	}
}

void mergesort(int A[],int left,int right)
{
	if(left + 1 < right)
	{
		int mid = (left + right) / 2;
		mergesort(A,left,mid);
		mergesort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int main()
{
	int A[MAX];
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", A + i);
	}
	mergesort(A,0,n);
	for(i = 0; i < n; i++)
	{
		if(i)
		{
			printf(" ");
		}
		printf("%d", A[i]);
	}
	printf("\n%d\n", cnt);
	
	return 0;
}
