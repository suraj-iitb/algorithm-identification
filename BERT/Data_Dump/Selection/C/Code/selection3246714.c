#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int n, i, j, swaps = 0, tmp, min_i;
	int* data;
	scanf("%d", &n);
	data = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", data + i);
	}
	for (i = 0; i < n; i++) {
		min_i = i;
		for (j = i; j < n; j++) {
			if (data[j] < data[min_i]) {
				min_i = j;
			}
		}
		if (min_i != i) {
			tmp = data[i];
			data[i] = data[min_i];
			data[min_i] = tmp;
			swaps++;
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d", *(data + i));
		if (i < n - 1) printf(" ");
		else printf("\n");
	}
	printf("%d\n", swaps);
	free(data);
	return 0;
}
