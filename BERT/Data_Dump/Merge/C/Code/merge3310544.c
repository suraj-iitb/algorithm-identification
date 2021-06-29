#include <stdio.h>
#define ENU 500000
#define INF 1000000000

void mergeSort(int S[], int, int);
void merge(int S[], int, int, int);
int left, right, S[ENU], enu, count = 0;


int main() {
	int i, j;

	scanf("%d", &enu);
	for (i = 0; i < enu; i++) {
		scanf("%d", &S[i]);
	}
	left = 0;
	right = enu;
	mergeSort(S, left, right);
	for (i = 0; i < enu - 1; i++) {
		printf("%d ", S[i]);
	}
	printf("%d\n", S[enu - 1]);
	printf("%d\n", count);
	return 0;
}


void mergeSort(int S[], int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(S, left, mid);
		mergeSort(S, mid, right);
		merge(S, left, mid, right);
	}
}

void merge(int S[], int left, int mid, int right) {
	int n1, n2, i, j, k;
	n1 = mid - left;
	n2 = right - mid;

	int L[n1], R[n2];
	for (i = 0; i < n1; i++) {
		L[i] = S[left + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = S[mid + j];
	}

	L[n1] = INF;
	R[n2] = INF;
	i = 0;
	j = 0;

	for (k = left; k < right; k++) {
		count++;
		if (L[i] <= R[j]) {
			S[k] = L[i];
			i++;
		}
		else {
			S[k] = R[j];
			j++;
		}
	}
}


