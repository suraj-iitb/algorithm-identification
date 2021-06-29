#include <stdio.h>

int bubble_sort(int *A, int N)
{
	int i, cnt = 0, flag = 1;
	while (flag) {
		flag = 0;
		for (i = N - 1; i > 0; i--) {
			if (A[i] < A[i - 1]) {
				int tmp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = tmp;
				flag = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main(int argc, char** argv)
{
	int i, num, arr[100];

	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	int cnt = bubble_sort(arr, num);

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
