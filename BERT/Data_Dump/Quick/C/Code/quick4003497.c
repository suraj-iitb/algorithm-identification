#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

struct Card{
	char suit;
	int value;
};

struct Card L[MAX/2+2], R[MAX/2+2];

void merge(struct Card S[], int min, int mid, int max)
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
	
	L[n1].value = SENTINEL;
	R[n2].value = SENTINEL;
	i = 0;
	j = 0;
	
	for(k = min; k < max; k++)
	{
		if(L[i].value <= R[j].value)
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

void mergeSort(struct Card S[], int min, int max)
{
	if(min + 1 < max)
	{
		int mid = (min + max) / 2;
		mergeSort(S, min, mid);
		mergeSort(S, mid, max);
		merge(S,min, mid, max);
	}
}

int partition(struct Card S[], int p, int r)
{
	int i, j;
	struct Card temp, x;
	x = S[r];
	i = p - 1;
	for(j = p; j < r; j++)
	{
		if(S[j].value <= x.value)
		{
			i++;
			temp = S[i];
			S[i] = S[j];
			S[j] = temp;
		}
	}
	temp = S[i+1];
	S[i+1] = S[r];
	S[r] = temp;
	return i + 1;
}

void quickSort(struct Card S[], int p, int r)
{
	int q;
	if(p < r)
	{
		q = partition(S, p, r);
		quickSort(S, p, q - 1);
		quickSort(S, q + 1, r);
	}
}

int main(void)
{
	int n, i, v;
	struct Card A[MAX], B[MAX];
	char S[10];
	int stable = 1;
	
	scanf("%d", &n);
		
	for(i = 0; i < n; i++)
	{
		scanf("%s %d", S, &v);
		A[i].suit = B[i].suit = S[0];
		A[i].value = B[i].value = v;
	}
	
	mergeSort(A, 0, n);
	quickSort(B, 0, n - 1);
	
	for(i = 0; i < n; i++)
	{
		if(A[i].suit != B[i].suit)
		{
			stable = 0;
		}
	}
	
	if(stable == 1) printf("Stable\n");
	else printf("Not stable\n");
	for(i = 0; i < n ; i++)
	{
		printf("%c %d\n", B[i].suit, B[i].value);
	}
	return 0;
}
