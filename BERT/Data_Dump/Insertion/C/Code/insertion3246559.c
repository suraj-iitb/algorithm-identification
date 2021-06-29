#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main (void) {
	int n, i, j, key;
	int* data;
	scanf("%d", &n);
	data = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", data + i);
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d", data[j]);
			if (j < n - 1) printf(" ");
			else printf("\n");
		}
		key = data[i];
		j = i - 1;
		while (j >= 0 && data[j] > key) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;
	}
	for (j = 0; j < n; j++) {
		printf("%d", data[j]);
		if (j < n - 1) printf(" ");
		else printf("\n");
	}
	free(data);
	return 0;
}
