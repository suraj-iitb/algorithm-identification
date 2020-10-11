#include <stdio.h>
#include <math.h>

int main(void)
{
	int num, minj, tmt, i, j, n = 0;
	int a[200];

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < num; i++) {
		minj = i;
		for (j = i; j < num; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		tmt = a[i];
		a[i] = a[minj];
		a[minj] = tmt;

		if (minj != i) {
			n++;
		}

	}
	
	for (i = 0; i < num; i++) {
		printf("%d", a[i]);

		if (i != num - 1) {
			putchar(' ');
		}
		else {
			putchar('\n');
		}
	}

	printf("%d\n", n);

	return 0;
}
