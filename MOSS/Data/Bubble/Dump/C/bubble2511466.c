#include<stdio.h>

int main(){
	int i, j;
	int count;
	int N;
	scanf("%d\n", &N);

	int A[N];
	for(i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	
	count = 0;
	//BubbleSort(A)
	int flag = 1;
	while(flag) {
		flag = 0;
		for(j = N - 1; j > 0; --j) {
			if(A[j] < A[j-1]) {
				int tmp;
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				flag = 1;
				++count;
			}
		}
	}
	for(i = 0; i < N; ++i) {
		if(i == N-1)
			printf("%d\n", A[i]);
		else
			printf("%d ", A[i]);
	}
	printf("%d\n", count);
    return 0;
}
