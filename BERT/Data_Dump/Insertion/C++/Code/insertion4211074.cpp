#include <iostream>
#include <stdio.h>
using namespace std;

void trace(int [], int );

void insertionSort(int A[], int N) {
    int i, j, v;
    for (i = 1; i != N; ++i) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}

void trace(int A[], int N) {
    int i = 0;
    while (i < N) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", A[i]);
        ++i;
    }
    cout << endl;
}

int main() {
    int N, i, j;
    int A[100];
    
    std::cin >> N;
    for (i = 0; i < N; ++i ) {
        scanf("%d", &A[i]);
        
    }
    trace(A, N);
    insertionSort(A, N);
    return 0;
}
