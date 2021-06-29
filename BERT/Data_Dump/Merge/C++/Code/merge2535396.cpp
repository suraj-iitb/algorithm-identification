#include <cstdio>

#define MAX 500000
#define SENTINEL 2000000000

int cnt = 0;
int L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(int *s, int n, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++) L[i] = s[left + i];
	for (int i = 0; i < n2; i++) R[i] = s[mid + i];
	L[n1] = R[n2] = SENTINEL;
	//L[n1] = SENTINEL;
	//R[n2] = SENTINEL;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		cnt++;
		if (L[i] <= R[j]) {
			s[k] = L[i++];
		}
		else {
			s[k] = R[j++];
		}
	}
	return;
}

void mergeSort(int *s, int n, int left, int right) {
	//printf("@@@");
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(s, n, left, mid);
		mergeSort(s, n, mid, right);
		merge(s, n, left, mid, right);
	}
	return;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	int s[MAX];
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	mergeSort(s, n, 0, n);
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", s[i]);
	}
	printf("\n");
	printf("%d\n", cnt);
	return 0;
}
