#include <stdio.h>

int selection_sort(int *A, int N)
{
	int i, j, minj;
	int cnt = 0;
	for (i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			int tmp = A[i];
			A[i] = A[minj];
			A[minj] = tmp;
			cnt++;
		}
	}
	return  cnt;
}

int main(int argc, char** argv)
{
	int i, num, arr[100];

	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	int cnt = selection_sort(arr, num);

	for (i = 0; i < num; i++) {
		if (i == num - 1) {
			printf("%d\n", arr[i]);
		}
		else {
			printf("%d ", arr[i]);
		}
	}
	printf("%d\n", cnt);
	return 0;
}
