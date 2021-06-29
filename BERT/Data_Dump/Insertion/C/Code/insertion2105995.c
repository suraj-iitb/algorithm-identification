#include <stdio.h>
void insertSort(int A[],int N) {
	int i, j, k, tmp, flag;
	flag = 0;
	
	for (k = 0; k < N; ++k) {
		printf("%d", A[k]);
		if (k != N-1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}

	
	for (i = 1; i < N; ++i) {
		tmp = A[i];
//		printf("\n");
//		printf("%d\n", tmp);
		j = i - 1;
		flag = 1;
		while (j >= 0 && A[j] > tmp) {
			flag = 1;
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = tmp;
		if (flag) {
			//		printf("\n");
			for (k = 0; k < N; ++k) {
				printf("%d", A[k]);
				if (k != N-1) printf(" ");
			}
			printf("\n");
		}
	}
}

int main(void)
{
	int A[100] = {0};
	int i, j, n;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	insertSort(A, n);
	return 0;
}
