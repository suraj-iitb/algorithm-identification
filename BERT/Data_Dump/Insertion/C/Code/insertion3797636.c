#include <stdio.h>

int main() {
    int N, temp, j, k;
    scanf("%d", &N);
    int A[N];
    for (int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
    for (j=1; j<N; j++) {
        for (int l=0; l<N; l++) {
            printf("%d", A[l]);
            if (l == (N - 1)) {
                putchar('\n');
            } else {
                putchar(' ');
            }
        }
        temp = A[j];
        k = j - 1;
        while ((k >= 0) && (A[k] > temp)) {
            A[k+1] = A[k];
            k--;
        }
        A[k+1] = temp;
    }
    for (int m=0; m<N; m++) {
        printf("%d", A[m]);
        if (m == (N - 1)) {
            putchar('\n');
        } else {
            putchar(' ');
        }
    }
    
    return 0;
}

