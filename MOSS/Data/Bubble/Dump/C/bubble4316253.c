#include <stdio.h>
#define swap(type, a, b) {type tmp = a; a = b; b = tmp;}

int bubbleSort(int *a, int n) {
    int i, j, sum, flag;
    j = 0; sum = 0; flag = 1;
    while (flag) {
        flag = 0;
        for (i = n - 1; i > j; i--) {
            if (a[i] < a[i - 1]) {
                swap(int, a[i], a[i - 1]);
                sum++;
                flag = 1;
            }
        }
        j++;
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

    ans = bubbleSort(A, N);

    for (idx = 0; idx < N; idx++) {
        printf("%d", A[idx]);
        if (idx < N - 1) printf(" ");
        else printf("\n");
    }

    printf("%d\n", ans);

    return 0;
}
