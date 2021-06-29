#include <stdio.h>
void output(int data[100], int n) {
	int i;
	const char *fmt = "%d";

	for (i = 0; i < n; i++) {
		printf(fmt, data[i]);
		fmt = " %d";
	}
	putchar('\n');
}

int main(void) {
	int n, i, j, data[100], key;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", data+i);
	}
	output(data, n);
	for (j = 1; j < n; j++) {
		key = data[j];
		i = j - 1;
		while (i >= 0 && data[i] > key) {
			data[i+1] = data[i];
			i -= 1;
		}
		data[i+1] = key;
		output(data, n);
	}
	return 0;
}
