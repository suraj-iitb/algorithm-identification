#include<stdio.h>

#define MAX 500000

int a[MAX], cp[MAX], count = 0;

void merge_sort(int a[], int left, int right) {
	int i, j, k, mid;

	if (left < right) {
		mid = (left + right) / 2; 
		merge_sort(a, left, mid);  
		merge_sort(a, mid + 1, right);
		for (i = mid; i >= left; i--) { cp[i] = a[i]; } 
		for (j = mid + 1; j <= right; j++) {
			cp[right - (j - (mid + 1))] = a[j]; 
		}

		i = left;
		j = right;

		for (k = left; k <= right; k++) {
			if (cp[i] < cp[j]) { a[k] = cp[i++]; }
			else { a[k] = cp[j--]; }
			count++;
		}
	}
}

int main(void) {
	int i, n;

	scanf("%d", &n);
	for (i = 0; i < n; i++) { scanf("%d", &a[i]); }

	merge_sort(a, 0, n - 1);

	for (i = 0; i < n; i++) { 
		printf("%d", a[i]);  
		if(i != n-1) printf(" ");
	}
	printf("\n");
	printf("%d\n", count);

	return 0;
}

