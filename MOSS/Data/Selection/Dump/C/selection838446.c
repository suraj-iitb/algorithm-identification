#include <stdio.h>

void p(int A[],int n){
    int i;
    for (i = 0; i < n; i++) {
        if (i != 0) putchar(' ');
        printf("%d", A[i]);
    }
    putchar('\n');
}

int main(){
    int n, A[100], i, j, min, c = 0, swap;
    scanf("%d", &n);
    for (i = 0;i < n;i++) scanf("%d", A + i);
    for (i = 0;i < n; i++) {
        min = i;
        for (j = i;j < n; j++) if (A[j] < A[min]) min = j;
            if (i != min){
                swap = A[i];
                A[i] = A[min];
                A[min] = swap;
                c++;
            }
    }
    p(A, n);
    printf("%d\n", c);
    return 0;
}
