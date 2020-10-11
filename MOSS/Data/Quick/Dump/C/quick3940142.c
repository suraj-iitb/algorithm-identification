#include<stdio.h>



struct Card
{
	int vaule;
	char s[10];
	int sign;
};

//struct Card L[100010 / 2], R[100010 / 2];

//void merge(struct Card A[], int left, int mid, int right)
//{
//	int n1, n2;
//	n1 = mid - left;
//	n2 = right - mid;
//	for (int i = 0; i < n1; i++) L[i] = A[left + i];
//	for (int i = 0; i < n2; i++) R[i] = A[mid + i];
//	L[n1].vaule = R[n2].vaule = 0x7fffffff;
//
//	for (int k = left, i = 0, j = 0; k < right; k++)
//	{
//		if (L[i].vaule <= R[j].vaule)
//			A[k] = L[i++];
//		else
//			A[k] = R[j++];
//	}
//}

//void mergeSort(struct Card A[], int left, int right)
//{
//	if (left + 1 < right)
//	{
//		int mid = (left + right) / 2;
//		mergeSort(A, left, mid);
//		mergeSort(A, mid, right);
//		merge(A, left, mid, right);
//	}
//}

int partition(struct Card A[], int left, int right)
{
	int x = A[right].vaule;
	int i;
	i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (A[j].vaule <= x)
		{
			i++;
			struct Card t = A[j];
			A[j] = A[i];
			A[i] = t;
		}
	}
	struct Card t = A[i + 1];
	A[i + 1] = A[right];
	A[right] = t;
	return i + 1;
}

void quickSort(struct Card A[], int left, int right)
{
	if (left < right)
	{
		int p = partition(A, left, right);
			quickSort(A, left, p - 1);
			quickSort(A, p + 1, right);
	}
}

int main()
{
	//struct Card A[100010], B[100010];
	struct Card B[100010];
	int n, stable = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		//scanf("%s%d", A[i].s, &A[i].vaule);
		//A[i].sign = i;
		//B[i] = A[i];
		scanf("%s%d", B[i].s, &B[i].vaule);
		B[i].sign = i;
	}
	//mergeSort(A, 0, n);
	quickSort(B, 0, n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		if (B[i].vaule == B[i + 1].vaule && B[i].sign > B[i + 1].sign)
		{
			stable = 0;
			break;
		}
	}
	printf("%s", stable ? "Stable\n" : "Not stable\n");
	for (int i = 0; i < n; i++)
		printf("%c %d\n", B[i].s[0], B[i].vaule);
}
