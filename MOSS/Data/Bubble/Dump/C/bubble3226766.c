#include <stdio.h>
#include <math.h>

int main(void)
{
	int num, tmt, flag = 1, i, j, n = 0;
	int a[200];

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < num; i++) {
		flag = 1;

		while (flag) {
			flag = 0;
			for (j = num - 1; j > 0; j--) {
				if (a[j] < a[j - 1]) {
					tmt = a[j];
					a[j] = a[j - 1];
					a[j - 1] = tmt;
					n++;
				}
			}
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
