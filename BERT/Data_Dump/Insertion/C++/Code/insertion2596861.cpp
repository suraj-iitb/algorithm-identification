#include<stdio.h>
int main()
{
	int i, n, v, j, c;
	int a[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 1; i < n; i++) {
		for (c = 0; c < n; c++) {
			if (c == n - 1) {
				printf("%d\n", a[c]);
				break;
			}
			printf("%d ", a[c]);
		}
		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j]>v ) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		
		
	}
	for (c = 0; c < n; c++) {
		if (c == n - 1) {
			printf("%d\n", a[c]);
			break;
		}
		printf("%d ", a[c]);
	}

}
