#include <stdio.h>

void print(int A[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int n) {
    print(A, n);
    int i, j, t;
    for(i = 1; i < n; i++) {
        t = A[i];
        j = i-1;
        while(j >= 0 && A[j] > t) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = t;
        print(A, n);
    }
}

int main(void) {
    int n, A[100], i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);

    insertionSort(A, n);

    return 0;
}
