#include<iostream>
#include<stdio.h>
using namespace std;

void p(int A[], int N) {
    int i = 0;
    for (i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void sort(int A[], int N) {
    int i, j, v;
    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        p(A, N);
    }
}

int main() {
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    p(a, n);
    sort(a, n);
}
