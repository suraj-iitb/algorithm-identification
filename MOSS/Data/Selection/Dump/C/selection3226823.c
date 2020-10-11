#include <stdio.h>
#include <math.h>

int main(void)
{
	int n,A[10000];
	int i, j, k, tmp, minj = 0;
	int count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	
	for (i = 0;i <= n - 1;i++) {
		minj = i;
		for (j = i;j <= n - 1;j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (minj != i) {
			tmp = A[i];
			A[i] = A[minj];
			A[minj] = tmp;
			count++;
		}
	}

	for (k = 0; k < n; k++) {
		printf("%d", A[k]);
		if (k != n - 1) {
			printf(" ");
		}
		else
		{
			printf("\n%d\n",count);
		}
	}
	
	return 0;
}
