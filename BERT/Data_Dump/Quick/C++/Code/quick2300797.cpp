#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define DEKAI 2000000000
#define MAX 100000

struct Card
{
	char suit;
	int value;
};


Card L[MAX/2+2],R[MAX/2+2];

void merge(struct Card A[],int left,int mid,int right)
{
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; ++i)
	{
		L[i] = A[left + i];
	}
	for (int i = 0; i < n2; ++i)
	{
		R[i] = A[mid + i];
	}
	L[n1].value = R[n2].value = DEKAI;
	int i = 0;
	int j = 0;
	for (int k = left; k < right ; ++k)
	{
		if (L[i].value <= R[j].value)
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

void mergesort(struct Card A[],int left,int right)
{
	if (left+1 < right)
	{
		int mid = (left + right)/2;
		mergesort(A,left,mid);
		mergesort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int partition(struct Card A[],int p,int r)
{
	Card x = A[r];
	int i = p-1;
	for (int j = p; j < r; ++j)
	{
		if (A[j].value <= x.value)
		{
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}

void quickSort(struct Card A[],int p,int r)
{
	int q;
	if (p < r)
	{
		q = partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main()
{
	int n,v;
	Card A[MAX],B[MAX];
	int stable = 1;
	char S[100];
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d",&S,&v);
		A[i].suit = B[i].suit = S[0];
		A[i].value = B[i].value = v;
	}

	mergesort(A,0,n);
	quickSort(B,0,n-1);

	//??????
	for (int i = 0; i < n; ++i)
	{
		if (A[i].suit != B[i].suit)
		{
			stable = 0;
		}
	}

	if (stable)
	{
		printf("Stable\n");
	}
	else
	{
		printf("Not stable\n");
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%c %d\n",B[i].suit,B[i].value);
	}
	return 0;
}
