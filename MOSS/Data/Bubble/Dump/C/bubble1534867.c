#include<stdio.h>
int main() {
	int i, j, n, t, sw = 0, mini, a[100], flag = 1;
	scanf("%d", &n);
	flag = 1;
	for (i = 0; i < n; i++)scanf("%d", &a[i]);
	for (i = 0; flag; i++) {
		flag = 0;
		for (j = n - 1; j >= i + 1; j--) {
			if (a[j] < a[j - 1]) {
				t = a[j];
				a[j] = a[j - 1];
				a[j - 1] = t;
				sw++;
				flag = 1;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i != n - 1)printf(" ");
	}
	printf("\n%d\n", sw);
	return 0;
}
