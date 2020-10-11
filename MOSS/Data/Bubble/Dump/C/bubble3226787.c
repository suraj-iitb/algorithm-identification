#include <stdio.h>
#include <math.h>

int main(void)
{
	int n,A[10000];
	int flag;
	int i, j, k, tmp, count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	flag = 1;

	while (flag) {
		flag = 0;
		for (j = n - 1;j > 0;j--) {
			if (A[j] < A[j - 1]) {
				tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = 1;
				count++;
			}
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
