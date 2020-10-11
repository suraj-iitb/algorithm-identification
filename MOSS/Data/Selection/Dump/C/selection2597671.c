#include<stdio.h>

int main(void) {
	int N, A[100], i, j, minj, s, sw;
        sw = 0;

	scanf("%d", &N);

	for (i = 0;i < N;i++) scanf("%d", &A[i]);

	for (i = 0;i < N - 1;i++) {
		minj = i;
                for(j = i;j < N;j++){
                  if(A[j] < A[minj]) minj = j;
                }
        s = A[i];
        A[i] = A[minj];
        A[minj] = s;
        if(i != minj) sw++;
        }

	for (i = 0;i < N;i++) {
	  if (i != 0) printf(" ");
	  printf("%d", A[i]);
	}

	printf("\n");

	printf("%d\n", sw);

	return 0;
}
