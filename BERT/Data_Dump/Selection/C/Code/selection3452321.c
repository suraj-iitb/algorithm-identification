#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int selectionsort(int N, int *num) {
	int itmp, sw, change = 0;
	for (int i = 0; i < N; i++) {
		sw = FALSE;
		int minj = i;
		for (int j = i; j < N; j++) {
			if (num[j] < num[minj]) {
				minj = j;
				sw = TRUE;
			}
		}
		itmp = num[i];
		num[i] = num[minj];
		num[minj] = itmp;
		if (sw) {
			change++;
		}
	}
	return change;
}

int main(void) {
	int N, changed;
	int num[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", num + i);
	}
	changed = selectionsort(N, num);
	for (int i = 0; i < N; i++) {
		if (i) {
			printf(" ");
		}
		printf("%d", num[i]);
	}
	printf("\n%d\n", changed);
	return 0;
}
