#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>

int main() {
	int *A, n, i, j, cnt = 0, tmp;

	scanf("%d", &n);
	A = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; ++i) scanf("%d", A + i);

	for (i = 0; i < n; i++)
		for (j = n - 1; j > i; --j)
			if (*(A + j - 1) > *(A + j))
				tmp = *(A + j), *(A + j) = *(A + j - 1), *(A + j - 1) = tmp, cnt++;
	for (i = 0; i < n; i++) printf("%d%c", A[i], i < n - 1 ? ' ' : '\n');
	printf("%d\n", cnt);
	free(A);
	return 0;
}
