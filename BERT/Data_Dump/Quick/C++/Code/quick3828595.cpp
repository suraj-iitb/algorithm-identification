#include<stdio.h>



struct Card {
	char suit;
	int value;
};


Card L[50000], R[50000];

void merge(Card A[], int left, int mid, int right)
{
	int n1, n2, i, j;
	n1 = mid - left;
	n2 = right - mid;
	for (i = 0; i < n1; i++)
	{
		L[i] = A[i + left];
	}

	for (i = 0; i < n2; i++)
	{
		R[i] = A[i + mid];
	}
	L[n1].value = 2000000000;
	R[n2].value = 2000000000;
	i = j = 0;
	for (int k = left; k < right; k++)
	{
		if (L[i].value <= R[j].value)
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}

void mergeSort(Card A[], int left, int right)
{
	int mid;
	if (left + 1 < right)
	{
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}
int partition(Card A[],int p, int r)
{
	int i;
	Card x = A[r],t;
	i = p - 1;

	for (int j = p; j < r; j++)
	{
		if (A[j].value <= x.value)
		{
			i++;
			t = A[j];
			A[j] = A[i];
			A[i] = t;
		}
	}
	t = A[r];
	A[r] = A[i+1];
	A[i+1] = t;

	return i + 1;

}
void quickSort(Card A[], int p, int r)
{
	int q;
	if (p >= r)
		return;
	q = partition(A, p, r);
	quickSort(A, p, q - 1);
	quickSort(A, q+1, r);
}
int main()
{
	bool stable = true;
	Card A[100005], B[100005];
	int n,i;

	scanf("%d",&n);

	for (i = 0; i < n; i++)
	{
		scanf(" %c %d", &A[i].suit, &A[i].value);
		B[i] = A[i];
	}
	quickSort(A,0,n-1);
	mergeSort(B, 0, n);
	i = 0;
	while (i<n&&stable)
	{
		if (B[i].suit != A[i].suit)
			stable = false;
		i++;
	}
	if (stable)
		printf("Stable\n");
	else
		printf("Not stable\n");
	for (i = 0; i < n; i++)
	{
		printf("%c %d\n", A[i].suit, A[i].value);
	}

	return 0;
}
