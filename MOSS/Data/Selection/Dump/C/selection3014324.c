#include <stdio.h>

int sort(int a[], int n)
{
	int i, j, minj, temp;
	int cnt = 0;

	for (i = 0; i < n - 1; i++) {
		minj = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (minj != i) {
			cnt++;
			temp = a[i];
			a[i] = a[minj];
			a[minj] = temp;
		}
	}

	return cnt;
}

int main(void) {
	int n, cnt;
	int line[100];
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &line[i]);
	}

	cnt = sort(line, n);

	for (i = 0; i < n; i++) {
		printf("%d", line[i]);
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n%d\n", cnt);

	return 0;
}
