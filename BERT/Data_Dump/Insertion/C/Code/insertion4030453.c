#include <stdio.h>

#define N 100
#define A 1000

int main() {

	int i,j,k,n,a[A],v;

	scanf("%d",&n);

	for (i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}

	for (k = 0; k < n-1; k++) {
		printf("%d ", a[k]);
	}
	printf("%d", a[k]);

	for (i = 1; i < n; i++) {
		
		printf("\n");

		v = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
		}

		for (k = 0; k < n -1; k++) {
			printf("%d ", a[k]);
		}

		printf("%d", a[k]);
	}

printf("\n");

	return 0;

}

