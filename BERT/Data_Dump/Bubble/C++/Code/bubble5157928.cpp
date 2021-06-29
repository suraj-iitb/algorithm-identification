#include <stdio.h>
#include <algorithm>
using namespace std;

int bubbleSort(int A[], int N) {
    int sw = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = N -1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    int N, A[100], sw;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    sw = bubbleSort(A, N);

    for (int k = 0; k < N; k++) {
        if (k > 0) printf(" "); 
        printf("%d", A[k]);
    }
    printf("\n");

    printf("%d", sw);
    printf("\n");

	return 0;
}
