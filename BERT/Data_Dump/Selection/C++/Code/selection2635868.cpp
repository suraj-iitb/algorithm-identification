
#include <iostream>
#include <stdio.h>
#include <math.h>

#define MAX 101
int sum(0);

void print(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", sum);
}

void selectionSort(int A[], int n) {
    int i = 0;
    while (i != n-1) {
        int ch = 0;
        int min_i = i;
        for (int j = i+1; j < n; j++) {
            if (A[min_i] > A[j]) {
                min_i = j;
                ch = 1;
            }
        }
        if (ch) {
            std::swap(A[i], A[min_i]);
            sum++;
        }
        i++;
    }
    print(A, n);
}

void bubbleSort( int A[], int n ) {
    int i = 1;
    while (1) {
        for (int j = n-1; j >= i; j--) {
            if (A[j] < A[j-1]) {
                std::swap(A[j], A[j-1]);
                sum ++;
            }
        }
        if (i == n) break;
        i++;
    }
    print(A, n);
}

int main() {
    int n;
    int A[MAX];
    
    scanf( "%d", &n );
    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &A[i]);
    }
    selectionSort(A, n);
    
    return 0;
}
