#include <cstdio>

void trace(int A[], int N) {
	int i;
	for( i = 0; i < N; i++ ) {
		if(i > 0) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}

void bubbleSort(int A[], int N) {
	int j, flag, counter;
	flag = 1, counter = 0;
	while(flag) {
		flag = 0;
		for( j = N-1; j > 0; j-- )
			if( A[j] < A[j - 1] ) {
				int v = A[j - 1];
				A[j - 1] = A[j];
				A[j] = v;
				counter++;
				flag = 1;
			}
	}
	trace(A, N);
	printf("%d\n", counter);
}

int main()
{
	const int MAXN = 100;
	int N, i, A[MAXN];

	scanf("%d", &N);
	for( i = 0; i < N; i++ ) scanf("%d", &A[i]);

	bubbleSort(A, N);

	return 0;
}
