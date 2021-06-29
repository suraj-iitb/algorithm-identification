#include <stdio.h>
#include <math.h>

int main(void)
{
	int num, x, i, j, n;
	int a[200];

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &a[i]);
	}

	for (n = 0; n < num; n++) {
		printf("%d", a[n]);

		if (n != num - 1) {
			putchar(' ');
		}
		else {
			putchar('\n');
		}
	}

	for (i = 1; i < num; i++) {
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j+1] = a[j];
			j--;
		}
		a[j + 1] = x;

		for (n = 0; n < num; n++) {
			printf("%d", a[n]);
			
			if (n != num - 1) {
				putchar(' ');
			}
			else {
				putchar('\n');
			}
		}
	}

	return 0;
}
