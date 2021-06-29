#include <bits/stdc++.h>

using namespace std;

const int SENTINEL = 1e9;

int c = 0;

void merge(int A[], int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	
	int L[n1], R[n2];
	
	for(int i = 0; i < n1; i++)
		L[i] = A[left + i];
	
	for(int i = 0; i < n2; i++)
		R[i] = A[mid + i];
	
	L[n1] = SENTINEL;
	R[n2] = SENTINEL;
	
	int i = 0, j = 0;
	
	for(int k = left; k < right; k++)
	{
		if(L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
		c++;
	}
}

void mergeSort(int A[], int left, int right)
{
	if(left+1 < right)
	{
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
	   	mergeSort(A, mid, right);
	   	merge(A, left, mid, right);
	}
}

void printArray(int A[], int n)
{
	int i;
	for(i = 0; i < n-1; i++)
		printf("%d ", A[i]);
	printf("%d\n", A[i]);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int A[n];
	
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	
	mergeSort(A, 0, n);
	
	printArray(A, n);
	printf("%d\n", c);
	
	return 0;
}
