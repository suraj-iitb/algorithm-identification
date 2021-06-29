#include <stdio.h>
#include <math.h>

int main(void)
{
	int n,A[10000];
	float a;
	int i, j, k, l = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}


	for (k = 0; k < n; k++) {
		printf("%d", A[k]);
		if (k != n - 1) {
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}

	for (i = 1; i <= n - 1; i++) {
		
		a = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > a) {
			A[j + 1] = A[j];
			j--;
			A[j + 1] = a;
		}

		
		for (k = 0; k < n; k++) {
			printf("%d", A[k]);
			if (k != n - 1) {
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
		

		
	}

	return 0;
}
