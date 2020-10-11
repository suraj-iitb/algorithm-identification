#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>

int main(){
	int *A, n, i, j, cnt = 0, tmp, iMin, iTmp;;

	scanf("%d", &n);
	A = (int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; ++i) scanf("%d", A+i);

	for (i = 0; i < n-1 ; i++) {
		iMin = iTmp = i;
		for (j = i; j < n; j++) {
			if (*(A + iMin) > *(A + j)) {
				iMin = j;
			}
		}
		if (iTmp != iMin) {
			tmp = *(A + i); *(A + i) = *(A + iMin); *(A + iMin) = tmp;
			cnt++;
		}
	}
	for (i = 0; i < n; i++) printf("%d%c", A[i], i < n - 1 ? ' ' : '\n');
	printf("%d\n", cnt);
	free(A);
	return 0;
}
