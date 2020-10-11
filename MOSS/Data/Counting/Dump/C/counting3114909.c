#include <stdio.h>
#define MAX_N 2000001
#define MAX_V 10001
 
unsigned short A[MAX_N];
unsigned short B[MAX_N];
int C[MAX_V];
 
void countingSort(int n) {
    int i, j;
    for (i = 0; i < MAX_V; i++) {
        C[i] = 0;
    }
 
    for (j = 1; j <= n; j++) {
        C[A[j]]++;
    }
    for (i = 1; i < MAX_V; i++) {
        C[i] = C[i] + C[i-1];
    }
 
    for (j = n; j >= 1; j--) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}
 
 
int main(void) {
    int i, n;
 
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%hd", &A[i]);
    }
 
    countingSort(n);
 
    for (i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", B[i]);
    }
    putchar('\n');
    return 0;
}
