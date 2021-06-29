#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000
typedef struct card {
	char suit;
	int num;
}Card;

Card L[MAX/2 + 2], R[MAX/2 +2];

void merge(Card A[], int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left;
	int n2 = right - mid;
	for(i = 0; i < n1; i++)
		L[i] = A[left+i];
	for(i = 0; i < n2; i++)
		R[i] = A[mid+i];
	L[n1].num = R[n2].num = SENTINEL;
	i = j = 0;
	for(k = left; k < right; k++) {
		if(L[i].num <= R[j].num) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}
}

void mergeSort(Card A[], int left, int right)
{	
	if(left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int partition(Card A[], int p, int r)
{
	int i, j;
	Card x, t;
	x = A[r];
	i = p - 1;
	for(j = p; j < r; j++) {
		if(A[j].num <= x.num) {
			i++;
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}
	t = A[i+1];
	A[i+1] = A[r];
	A[r] = t;

	return i+1;
}

void quickSort(Card A[], int p, int r)
{
	if(p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}

int main()
{	
	int i, n, idx;
	int flag = 1;
	char spe;
	Card A[MAX], B[MAX];
	scanf("%d%c", &n, &spe);

	for(i = 0; i < n; i++) {
		scanf("%c%d%c", &A[i].suit, &A[i].num, &spe);
		B[i].suit = A[i].suit;
		B[i].num = A[i].num;
	}

	quickSort(A, 0, n-1);
	mergeSort(B, 0, n);

	for (i = 0; i < n; i++)
		if(A[i].suit != B[i].suit)
			flag = 0;

	if(flag)
		printf("Stable\n");
	else
		printf("Not stable\n");

	for (i = 0; i < n; i++)
		printf("%c %d\n", A[i].suit, A[i].num);

    return 0;
}
