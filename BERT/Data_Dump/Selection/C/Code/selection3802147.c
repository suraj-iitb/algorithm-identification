#include <stdio.h>

int main() {
    int N, min, temp, cou = 0;
    scanf("%d", &N);
    int A[N];
    for (int x=0; x<N; x++) {
        scanf("%d", &A[x]);
    }
    
    for (int i=0; i<N; i++) {
        min = i;
        for (int j=i; j<N; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
        if (i != min) {cou++;}
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

