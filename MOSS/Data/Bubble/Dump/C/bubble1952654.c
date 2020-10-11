#include <stdio.h>
#define N 100
void swap(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int BubbleSort(int array[], int n) {
	int i, j, count;

	count = 0;
	for (i = 0; i < n; i++) {
		for (j = n - 1; j > i; j--) {
			if (array[j - 1] > array[j]) {
				swap(&array[j - 1], &array[j]);
				count++;
			}
		}
	}
	return count;
}
int main() {

	int n,k, array[N];
	scanf("%d", &n);
	for (k = 0; k < n; k++)
		scanf("%d", &array[k]);

	int count = BubbleSort(array, n);

	int i;
	for (i = 0; i < n; i++) {
		if (i != 0) 
			printf(" ");
		printf("%d", array[i]); 
	}
	printf("\n%d\n", count);
	return 0;
}
