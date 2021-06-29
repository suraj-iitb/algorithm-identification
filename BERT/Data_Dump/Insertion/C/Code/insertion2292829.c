#include <stdio.h>
void printArray(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	printf("\n");
}
int main(void) {
	int i, n, j;
	int A[100];
	fscanf(stdin, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(stdin, "%d", &(A[i]));
	}
	printArray(A, n);
	for (j = 1; j < n; j++) {
		int key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
		printArray(A, n);
	}
	return 0;
}
