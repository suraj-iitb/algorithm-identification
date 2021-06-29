#include <stdio.h>

#define MAX_DATA 500001

int temp[MAX_DATA];
int cnt = 0;

void mergeSort(int x[], int left, int right)
{
	int mid, i, j, k;

	if (left < right) {

		mid = (left + right) / 2;
		mergeSort(x, left, mid);
		mergeSort(x, mid + 1, right);

		for (i = left; i <= mid; i++)
			temp[i] = x[i];

		for (i = mid + 1, j = right; i <= right; i++, j--)
			temp[i] = x[j];

		i = left;
		j = right;

		for (k = left; k <= right; k++) {
			cnt++;
			if (temp[i] <= temp[j])
				x[k] = temp[i++];
			else
				x[k] = temp[j--];
		}

	}
}

int main(void) {
	int n;
	int line[500001];
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &line[i]);
	}

	mergeSort(line, 0, n - 1);

	for (i = 0; i < n; i++) {
		printf("%d", line[i]);
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n%d\n", cnt);

	return 0;
}
