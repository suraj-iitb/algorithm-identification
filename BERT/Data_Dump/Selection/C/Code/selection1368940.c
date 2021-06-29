#include <stdio.h>

#define DEF_ELM_MAX 100

	int R[DEF_ELM_MAX];

void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}



int selectionSort(int *A, int N) // N??????????´??????????0-?????????????????????A
{
	int i;
	int j;
	int minj;
	int cnt = 0;
	int flag;

	for ( i = 0 ; i < N ; i++ ) {
		minj = i;
		flag = 0;
		for ( j = i ; j < N ; j++ ) {
			if ( A[j] < A[minj] ) {
				minj = j;
				flag = 1;
			}
		}
		if (flag) {
			swap(&A[i], &A[minj]);
			cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	int N;
	int i;

	int ans;
//
	scanf("%d", &N);
	for ( i = 0 ; i < N ; i++ ) {
		scanf("%d", &R[i]);
	}
//
	ans = selectionSort(R, N);
//
	for ( i = 0 ; i < N ; i++ ) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", R[i]);
	}
	printf("\n%d\n", ans);
	return 0;
}
