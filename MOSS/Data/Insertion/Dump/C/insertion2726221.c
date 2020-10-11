#include <stdio.h>

void print(int array[], int size) {
	for(int i = 0; i < size-1; i++) {
		printf("%d ", array[i]);
	}
	printf("%d\n", array[size-1]);

	return;
}

void insertion_sort(int array[], int size) {
	for(int i = 1; i < size; i++) {
		int tmp = array[i];
		int j = i - 1;
		while(j >= 0 && array[j] > tmp) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = tmp;

		print(array, size);
	}
}
int main() {
	int N;
	int A[100];
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		/*printf("%d-%d, ", i, A[i]);*/
	}

	print(A, N);
	insertion_sort(A, N);

	return 0;
}


