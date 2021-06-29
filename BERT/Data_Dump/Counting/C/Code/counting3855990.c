#include <stdlib.h>
#include <stdio.h>
typedef long long int ll;
int main() {
	unsigned short *A, *B;

	int C[10001];
	int N;
	scanf("%d", &N);
	A = malloc(sizeof(short) * N + 1);
    B = malloc(sizeof(short) * N + 1);
    
    for (int i = 0; i <= 10000; i++) C[i] = 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%hu", &A[i + 1]);
        C[A[i + 1]]++;
    }
    for (int i = 1; i <= 10000; i++) C[i] = C[i] + C[i - 1];
    for (int j = 1; j <= N; j++) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    for (int i = 1; i <= N; i++) {
        if (i > 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
    
    return 0;
}
