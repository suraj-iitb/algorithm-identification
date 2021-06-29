#include <stdio.h>

int sort(int a[], int n)
{
	int i, j, temp;
	int cnt = 0;

	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				cnt++;
			}
		}
	}

	return cnt;
}

int main(void) {
	int n, cnt;
	int line[100];
	int i;

	scanf("%d" ,&n);
	
	for (i = 0; i < n;i++) {
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
