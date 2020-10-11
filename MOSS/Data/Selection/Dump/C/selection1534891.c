#include<stdio.h>
int main() {
	int i, j, n, v, sw = 0, minj, a[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &a[i]);
	for (i = 0; i < n; i++) {
		minj = i;
		for (j = i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		v = a[i];
		a[i] = a[minj];
		a[minj] = v;
		if (minj != i)sw++;
	}
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i != n - 1)printf(" ");
	}
	printf("\n%d\n", sw);
	return 0;
}
