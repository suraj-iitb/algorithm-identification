#include <stdio.h>
int main(void) {
	int data[100], n, i, j, tmp, times = 0;
	const char *fmt = "%d";

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", data+i);
	}
	for (i = 0; i < n; i++) {
		for (j = n-1; j > i; j--) {
			if (data[j] < data[j-1]) {
				tmp = data[j];
				data[j] = data[j-1];
				data[j-1] = tmp;
				times++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf(fmt, data[i]);
		fmt = " %d";
	}
	printf("\n%d\n", times);
	return 0;
}
