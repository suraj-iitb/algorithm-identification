#include <stdio.h>
#define N 10000

int main() {
	int count,i,tmp,n,a[N],flag;

	count = 0;

	scanf("%d", &n);

	for (i = 0;i < n; i++) {
		scanf("%d", &a[i]);
	}

	flag = 1;
	while (flag) {
		flag = 0;
		for (i = 1;i < n; i++) {
			if (a[i] < a[i - 1]) {
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				count++;
				flag = 1;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d", a[i]);
		if(i < n -1)
			putchar(' ');
	}
	printf("\n");
	printf("%d\n", count);

	return 0;
}
