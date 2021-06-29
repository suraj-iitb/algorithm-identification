#include<stdio.h>
int main()
{
	int i, n, temp, j, c=0;
	int a[100];
	int flag = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	while (flag) {
		flag = 0;
		for (j = n - 1; j > 0; j--) {
			if (a[j] < a[j - 1]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				c++;
				flag = 1;
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (i == n - 1) {
			printf("%d\n", a[i]);
			break;
		}
		printf("%d ", a[i]);
	}
	printf("%d\n", c);

}
