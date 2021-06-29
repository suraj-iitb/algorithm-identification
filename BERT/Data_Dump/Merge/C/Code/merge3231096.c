#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 500000

int cnt = 0;

void merge(int a[], int left, int mid, int right) 
{
	int n1, n2, i, j, k;
	int L[MAX], R[MAX];
	
	n1 = mid - left + 1;
	n2 = right - mid;

	
	for (i = 0; i < n1; i++) {
		L[i] = a[left + i];
		cnt++;
	}
	for (i = 0; i < n2; i++) {
		R[i] = a[mid + i +1];
		cnt++;
	}
	L[n1] = 1000000000;
	R[n2] = 1000000000;
	
	i = 0;
	j = 0;
	for (k = left; k <= right; k++) {
		if (L[i] < R[j]) {
			a[k] = L[i++];
		} else {
			a[k] = R[j++];
		}
	}
	
}


void mergeSort(int a[], int left, int right)
{
	int mid;
	
	if (left >= right) {
		return;
	}
	mid = (left + right) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, mid, right);
}
	
	
int main()
{
	int s[MAX];
	int n, i;
	
	
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%d",&s[i]);
	}
	mergeSort(s, 0, n - 1);
	
	for (i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d",s[i]);
	}
	printf("\n");
	
	printf("%d\n",cnt);
	
return 0;
}	
