#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define SIZE 10001

int main() {
    int n, i, j;
    int C[SIZE];
    scanf("%d", &n);
    //??????????????§???????????????????????????:(
    //int A[MAX], B[MAX];

    unsigned short *A, *B;
    A = malloc(sizeof(short) * n+1);
    B = malloc(sizeof(short) * n+1);
    
    //????????§1?????????????????????
    for (i = 0; i < n; i++) scanf("%hu", &A[i]);

    for (i = 0; i < SIZE; i++) C[i] = 0;

    for (j = 0; j < n; j++) C[A[j]]++;

    for (i = 1; i < SIZE; i++) C[i] = C[i] + C[i-1];

    for (j = 0; j < n; j++) {
	B[C[A[j]]] = A[j];
	C[A[j]]--;
    }

    for (i = 1; i < n+1; i++) {
	if (i > 1) printf(" ");
	printf("%d", B[i]);
    }
    printf("\n");
    return 0;

}
