#include<stdio.h>
#include<string.h>

int a[1000];

int main(void){

	int i, j, k, n;
	int tmp;
	int v;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 1; i <= n; i++) {
		//ソートを一回終えるごとに出力//
		for (k = 0; k < n - 1 ; k++) {
			printf("%d ", a[k]);
		}
		printf("%d\n", a[n - 1]);

		//実際にソートを行う//
		j = i - 1;
		v = a[i];
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;

		}
	}
	return 0;
}
