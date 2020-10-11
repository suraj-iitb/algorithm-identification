#include<stdio.h>
 
int n, S[50000000],L[5000000],R[5000000];
int MAX = 1000000001;
int count = 0;

void merge(int S[], int left, int mid, int right) {
	int i = 0;
	int j = 0;
	int k = 0;
	int n1 = mid - left;
	int n2 = right - mid;

	for (i = 0;i < n1 ;i++) {
		L[i] = S[left + i];
		
	}
	for (i = 0;i < n2 ;i++) {
		R[i] = S[mid + i];

	}
	L[n1] = MAX;
	R[n2] = MAX;

	i = 0;
	j = 0;
	
	for (k = left;k < right;k++) {
		if (L[i] <= R[j]) {
			S[k] = L[i];
			i++;
			count++;
		}
		else {
			S[k] = R[j];
			j++;
			count++;
		}

	}
}

void mergesort(int S[], int left, int right) {
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergesort(S, left, mid);
		mergesort(S, mid, right);
		merge(S, left, mid, right);
	}
}


int main(void)
{
	int q, m[5000000];
	int i, j, k, l = 0;

	scanf("%d", &n);

	for (i = 0;i < n;i++) {
		scanf("%d", &S[i]);
	}

	mergesort(S, 0, n);

	for (i = 0;i < n;i++) {
		printf("%d", S[i]);
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n%d\n", count);

	return 0;
}
 

