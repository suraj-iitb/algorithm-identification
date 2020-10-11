#include <stdio.h>
#include <stdlib.h>
#define SENTINEL 1000000001

int g_num_swap = 0;

void merge(int *a, int left, int mid, int right) {
	int n1, n2, *L, *R, i, j, k;

	n1 = mid - left;
	n2 = right - mid;
	L = malloc(sizeof(int)*n1 + 1);
	R = malloc(sizeof(int)*n2 + 1);
	for (i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}
	for (i = 0; i < n2; i++) {
		R[i] = a[mid + i];
	}
	L[n1] = R[n2] = SENTINEL;

	i = j = 0;
	for (k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i++];
		} else {
			a[k] = R[j++];
		}
		g_num_swap++;
	}
	free(L);
	free(R);
}

void merge_sort(int *a, int left, int right) {
	int mid;

	if (left+1 < right) {
		mid = (left + right) / 2;
		merge_sort(a, left, mid);
		merge_sort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main(void) {
	int *s, n, i;
	const char *fmt = "%d";

	scanf("%d", &n);
	s = malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		scanf("%d", s+i);
	}
	merge_sort(s, 0, n);

	for (i = 0; i < n; i++) {
		printf(fmt, s[i]);
		fmt = " %d";
	}
	printf("\n%d\n", g_num_swap);
	free(s);
	return 0;
}
