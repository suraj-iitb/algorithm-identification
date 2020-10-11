#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int n, i, j, swaps = 0, tmp;
	int* data;
	scanf("%d", &n);
	data = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", data + i);
	}
	for (i = 0; i < n; i++) {
		for (j = n - 1; j > i; j--) {
			if (data[j] < data[j-1] ) {
				tmp = data[j-1];
				data[j-1] = data[j];
				data[j] = tmp;
				swaps++;
			}
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
