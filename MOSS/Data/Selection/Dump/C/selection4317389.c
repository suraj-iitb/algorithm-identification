#include <stdio.h>
#define swap(type, a, b) {type tmp = a; a = b; b = tmp;}

int selectionSort(int *a, int n) {
    int i, j, mini, sum;
    sum = 0;
    for (i = 0; i < n; i++) {
        mini = i;
        for (j = i; j < n; j++) {
            if (a[j] < a[mini]) mini = j;
        }
        if (i != mini) {
            swap(int, a[i], a[mini]);
            sum++;
        }
    }
    return sum;
}

int main(void) {
    int N;
    scanf("%d", &N);
    int A[N];
    int idx, ans;

    for (idx = 0; idx < N; idx++) {
        scanf("%d", &A[idx]);
    }

    ans = selectionSort(A, N);

    for (idx = 0; idx < N; idx++) {
        printf("%d", A[idx]);
        if (idx < N - 1) printf(" ");
        else printf("\n");
    }

    printf("%d\n", ans);

    return 0;
}
