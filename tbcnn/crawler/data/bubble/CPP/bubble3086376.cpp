#include <stdio.h>
#include <utility>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                count++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);
}
