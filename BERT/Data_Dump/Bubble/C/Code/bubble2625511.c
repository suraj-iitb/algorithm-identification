#include <stdio.h>

int arr[100];
int main(void){
	int i, j, N, count = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", arr + i);
	for (j = N; j; j--) {
		for (i = 1; i < j; i++) {
			if (arr[i - 1] > arr[i]) {
				arr[i - 1] ^= arr[i];
				arr[i] ^= arr[i - 1];
				arr[i - 1] ^= arr[i];
				count++;
			}
		}
	}
	printf("%d", *arr);
	for (i = 1; i < N; i++) printf(" %d", arr[i]);
	printf("\n%d\n", count);


}
