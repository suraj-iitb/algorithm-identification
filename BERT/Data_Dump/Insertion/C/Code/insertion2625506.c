#include <stdio.h>
int arr[1000];
int main(void) {
	int N, i, j, k, num;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", arr + i);
	for (i = 0; i < N; i++) {
		num = arr[i];
		for (j = 0; j < i && arr[j] < arr[i]; j++);
		for (k = i; k > j; k--) arr[k] = arr[k - 1];
		arr[j] = num;
		printf("%d", *arr);
		for (j = 1; j < N; j++) {
			printf(" %d", arr[j]);
		}
		printf("\n");
	}
}
