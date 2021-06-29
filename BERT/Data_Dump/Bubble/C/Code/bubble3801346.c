#include <stdio.h>

int main() {
    int N, temp, flg = 1, i = 0, cou = 0;
    scanf("%d", &N);
    int A[N];
    for (int x=0; x<N; x++) {
        scanf("%d", &A[x]);
    }
    
    while (flg) {
        flg = 0;
        for (int j=N-1; j>i; j--) {
            if (A[j] < A[j-1]) {
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                cou++;
            }
            flg = 1;
        }
        i++;
    }
    
    for (int y=0; y<N; y++) {
        printf("%d", A[y]);
        if (y == N - 1) {
            putchar('\n');
        } else {
            putchar(' ');
        }
    }
    printf("%d\n", cou);
    return 0;
}

