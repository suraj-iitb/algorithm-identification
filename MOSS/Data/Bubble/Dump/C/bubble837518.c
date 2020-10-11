#include <stdio.h>

void p(int A[], int n){
    int i;
    for (i = 0; i < n; i++) {
        if (i != 0) putchar(' ');
        printf("%d", A[i]);
    }
    putchar('\n');
}

int main(){
    int n, A[100], i, j, swap, c;
    scanf("%d", &n);
    for (i = 0; i < n;i++) scanf("%d", A + i);
    for (i = 1; i < n; i++) {
        j = n;
        while (i < j--) {
            if (A[j] < A[j - 1]) {
                swap = A[j];
                A[j] = A[j - 1];
                A[j - 1] = swap;
                c++;
            }
        }
    }
    p(A, n);
    printf("%d\n", c);
    
    return 0;
}
