#include <stdio.h>
#include <algorithm>
using namespace std;

int selectionSort(int A[], int N) {
    int min;
    int sw = 0;
    for (int i = 0; i < N; i++) {
        min = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (i != min) {
            swap(A[i], A[min]);
            sw++;
        }
    }
    return sw;
}

int main() {
    int N, A[100], sw;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    sw = selectionSort(A, N);

    for (int k = 0; k < N; k++) {
        if (k > 0) printf(" "); 
        printf("%d", A[k]);
    }
    printf("\n");

    printf("%d", sw);
    printf("\n");

	return 0;
}
