#import <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");

    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            A[j--] = v;
        }

        for (int i = 0; i < N; i++) {
            printf("%d", A[i]);
            if (i < N - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}

