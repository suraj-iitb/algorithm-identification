#include <stdio.h>
int arr[100];
int main(void) {
	int N, i, j, min, count = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", arr + i);
	for (i = 0; i < N; i++) {
		min = i;
		for (j = i; j < N; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			arr[min] ^= arr[i];
			arr[i] ^= arr[min];
			arr[min] ^= arr[i];
			count++;
		}
	}
	printf("%d", *arr);
	for (j = 1; j < N; j++) printf(" %d", arr[j]);
	printf("\n%d\n", count);
}
